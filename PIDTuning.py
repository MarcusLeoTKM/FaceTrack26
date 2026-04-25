"""
Date: 2026 Apr 25
PID tuning
"""
import time
import lgpio
import asyncio
import ReadMagneticField as RMF

# pins
dir_GPIO = 23       # GPIO pin 23, direction 
step_GPIO = 24      # GPIO pin 24, step
PWM_GPIO = 18

# Initiate GPIOs
h = lgpio.gpiochip_open(0)
lgpio.gpio_claim_output(h, dir_GPIO)
lgpio.gpio_claim_output(h, step_GPIO)
lgpio.gpio_claim_output(h, PWM_GPIO)

# PID parameters
KP = 40
KI = 0
KD = 0

PWM_MAX = 2240
PWM_MIN = 1

async def move_to_angle(angle: int):
    current_angle = await RMF.return_angle()
    while (abs(current_angle - angle) > 1):
        lgpio.gpio_write(h, step_GPIO, 1)
        time.sleep(0.001)
        lgpio.gpio_write(h, step_GPIO, 0)
        time.sleep(0.001)


def update_motor_speed(frequency):
    if frequency >= PWM_MAX:
        frequency = PWM_MAX
    elif frequency <= PWM_MIN:
        frequency = PWM_MIN
        
    lgpio.tx_pwm(h, PWM_GPIO, frequency, 50)


def compute_PID(error: float, kp = KP):
    p_term = error * KP
    i_term = 0
    d_term = 0
    # as it turns out, we don't need ki and kd
    return p_term + i_term + d_term


def pixel_angle_conversion(pixel: int) -> float:
    return pixel / 8.0


def change_dir(dir: int):
    lgpio.gpio_write(h, dir_GPIO, dir)


async def initialize_position(target_angle):
    lgpio.tx_pwm(h, PWM_GPIO, 2240, 50)
    while (True):
        await asyncio.sleep(0.001)
        current_angle = await RMF.return_angle()
        error = target_angle - current_angle
        print(error, target_angle, current_angle)

        if (abs(error) <= 1):
            update_motor_speed(0) # stop calibrating
            print("location ready")
            time.sleep(2)
            break

        update_frequency = compute_PID(error)
        if update_frequency <= 0:
            lgpio.gpio_write(h, dir_GPIO, 1)
        else:
            lgpio.gpio_write(h, dir_GPIO, 0)
            
        update_motor_speed(abs(update_frequency))

# asyncio.run(main())

