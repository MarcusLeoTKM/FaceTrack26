import asyncio
import cv2 as cv

import FaceRecog
import PIDTuning as PID

def camera_init():
    # Finds an available camera
    for i in range(0, 15):
        cam = cv.VideoCapture(i)
        if cam.isOpened(): 
            return i
        else:
            print("No camera found")


async def main_loop():
    print("program initialized")
    await PID.initialize_position(120) # initialize position

    global mid_width
    global mid_height

    camera_index = camera_init()

    cam = cv.VideoCapture(camera_index)
    cam.set(cv.CAP_PROP_FPS, 30)
    rval, frame = cam.read()

    screen_width = int(cam.get(cv.CAP_PROP_FRAME_WIDTH)) / 2        # Frame resized to half its original size
    screen_height = int(cam.get(cv.CAP_PROP_FRAME_HEIGHT)) / 2

    mid_width = screen_width / 2
    mid_height = screen_height / 2

    print("program initialized")

    while rval:
        rval, frame = cam.read()

        # Resizing
        scale_factor_x = 0.5
        scale_factor_y = 0.5
        resized_frame = cv.resize(frame, None, fx=scale_factor_x, fy=scale_factor_y, interpolation=cv.INTER_AREA)

        await FaceRecog.detect_face(resized_frame, mid_width, mid_height)
        key = cv.waitKey(1)
        if key == 27:
            break
            
    cam.release()

if __name__ == "__main__":
    asyncio.run(main_loop())
    