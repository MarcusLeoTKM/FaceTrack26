"""
Author: Leo Wang
Date: 2026 Mar 13


To reduce face detection latency
- Frame resized to half its original size.
- FPS increased from 10 to 30

To create a smoother motion
- Direction compensation algorithm was implemented
"""

import cv2 as cv
import time
import numpy as numpy
import asyncio

# module
# import ControlLogic             # Stepper Motor control functions
import classes.PIDTuning as PID
from classes.MagneticEncoder import MagneticEncoder

# CONSTANTS
TWIST_CONSTANT = 22             # Allow the centre to be slightly shifted
# SHIFT_CONSTANT = 32/18          # PX to MOTOR STEP ratio
# OVERSHOT = 0.65                 # Limits motor movement to prevent excessive motion
current_target = "RIGHT"        # Motor's initial direction

# Trained files
faceCascade = cv.CascadeClassifier('haarcascade_frontalface_default.xml')

def pixel_angle_conversion(pixel: int) -> float:
    return pixel / 8.0

async def detect_face(img, mid_width, mid_height, motor: MagneticEncoder):
    global current_target
    face_img = img.copy()
    face_rect = faceCascade.detectMultiScale(face_img, scaleFactor=1.3, minNeighbors=5)

    """
    face_rect is a tuple containing the (x, y) coordinate of the bottom left corner of the detected face
    and h are the width and height of the rectangle that contains the detected face
    """
    count = 0
    for (x, y, w, h) in face_rect:
        # face_rect only have either one or zero tuple
        center_x = int(x + w/2)
        center_y = int(y + h/2)


        if abs(center_x - mid_width) > TWIST_CONSTANT:     # No motion required if the center is within a range
            angle_offset = -1 * pixel_angle_conversion(center_x - mid_width)
            current_angle = await ME.return_angle()
            target_angle = current_angle - angle_offset

            update_frequency = 0

            while (True):
                previous_angle = current_angle
                current_angle = await ME.return_angle()
                if abs(current_angle - previous_angle) >= 100:
                    # sensor malfunction
                    continue

                error = target_angle - current_angle

                if count == 15:
                    # return to main to check if the person moved
                    count = 0
                    break

                count += 1

                if (abs(error) <= 3):
                    # within range
                    print("face centered")
                    break
                
                update_frequency = PID.compute_PID(error, 400)
                
                if update_frequency <= 0:
                    motor.change_dir(1)
                else:
                    motor.change_dir(0)

                # slowly energize the coil
                for i in range(5, 20):
                    motor.update_motor_speed(abs(update_frequency) * i/20)

                motor.update_motor_speed(abs(update_frequency))
        else:
            motor.update_motor_speed(0)
    return

