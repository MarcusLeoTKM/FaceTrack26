import time
import lgpio

dir_GPIO = 23       # GPIO pin 23, direction 
step_GPIO = 24      # GPIO pin 24, step

# Initiate GPIOs
h = lgpio.gpiochip_open(0)
lgpio.gpio_claim_output(h, dir_GPIO)
lgpio.gpio_claim_output(h, step_GPIO)

# dir = 1: left

async def motor_move(stp: int, dir: int):
    """
    Move the stepper motor stp steps
    """
    lgpio.gpio_write(h, dir_GPIO, dir)
    for i in range(stp):
    
        lgpio.gpio_write(h, step_GPIO, 1)
        time.sleep(0.001)
        lgpio.gpio_write(h, step_GPIO, 0)
        time.sleep(0.001)


async def dir_compensation(stp: int, dir: int):
    """
    When reversing directions, the internal coils of the stepper motors need to be re-energize
    requiring additional energy and steps to compensate.
    """
    lgpio.gpio_write(h, dir_GPIO, dir)
    for i in range(stp):
    
        lgpio.gpio_write(h, step_GPIO, 1)
        time.sleep(0.001)
        lgpio.gpio_write(h, step_GPIO, 0)
        time.sleep(0.001)