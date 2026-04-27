"""
Date: 2026 Apr 25
PID tuning
"""

import time

# PID parameters
KP = 40
KI = 0
KD = 0

# async def move_to_angle(angle: int):
#     current_angle = await RMF.return_angle()
#     while (abs(current_angle - angle) > 1):
#         lgpio.gpio_write(h, step_GPIO, 1)
#         time.sleep(0.001)
#         lgpio.gpio_write(h, step_GPIO, 0)
#         time.sleep(0.001)


def compute_PID(error: float, kp = KP):
    p_term = error * KP
    i_term = 0
    d_term = 0
    # as it turns out, we don't need ki and kd
    return p_term + i_term + d_term
