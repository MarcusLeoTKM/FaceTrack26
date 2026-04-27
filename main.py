import asyncio
import cv2 as cv

import FaceRecog
from classes.Motor import Motor

def camera_init():
    # Finds an available camera
    for i in range(0, 15):
        cam = cv.VideoCapture(i)
        if cam.isOpened():
            return i
        else:
            print("no camera found")


async def main_loop():
    # ---- initialization ----
    print("program initializing")
    # Motor 1
    Motor_A = Motor(
        360,
        0,
        120,    # initial position
        1,
        23,     # SPI dir: 23
        18      # SPI PWM: 18
    )
    await Motor_A.initialize_position() # initialize position
    camera_index = camera_init()

    print("program initialized")
    # ------------------------

    global mid_width
    global mid_height

    cam = cv.VideoCapture(camera_index)
    cam.set(cv.CAP_PROP_FPS, 30)
    rval, frame = cam.read()

    screen_width = int(cam.get(cv.CAP_PROP_FRAME_WIDTH)) / 2        # Frame resized to half its original size
    screen_height = int(cam.get(cv.CAP_PROP_FRAME_HEIGHT)) / 2

    mid_width = screen_width / 2
    mid_height = screen_height / 2

    while rval:
        rval, frame = cam.read()

        # Resizing
        scale_factor_x = 0.5
        scale_factor_y = 0.5
        resized_frame = cv.resize(frame, None, fx=scale_factor_x, fy=scale_factor_y, interpolation=cv.INTER_AREA)

        await FaceRecog.detect_face(resized_frame, mid_width, mid_height, Motor_A)
        key = cv.waitKey(1)
        if key == 27:
            break
            
    cam.release()

if __name__ == "__main__":
    asyncio.run(main_loop())
    
