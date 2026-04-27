"""
Date: 2026 Apr 27
Motor class
"""
from . import MagneticEncoder as ME
from . import PIDTuning as PID

import time
import lgpio
import asyncio

h = lgpio.gpiochip_open(0)

PWM_MAX = 2240
PWM_MIN = 1

def check_angle_boundary(angles):
    for angle in angles:
        if not (0 <= angle and angle <= 360):
            return False
    return True


class Motor:
    def __init__ (
        self, MAX_ANGLE: float, MIN_ANGLE: float, INIT_ANGLE: float,
        I2C_op: int, SPI_dir_PIN: int, SPI_PWM_PIN: int
    ):
        if (not (check_angle_boundary([MAX_ANGLE, MIN_ANGLE, INIT_ANGLE]))):
            raise ValueError("invalid angle")

        self.MAX_ANGLE = MAX_ANGLE
        self.MIN_ANGLE = MIN_ANGLE
        self.INIT_ANGLE = INIT_ANGLE

        self.SPI_dir_PIN = SPI_dir_PIN              # SPI pins
        self.SPI_PWM_PIN = SPI_PWM_PIN

        lgpio.gpio_claim_output(h, SPI_dir_PIN)     # initialize SPI pins
        lgpio.gpio_claim_output(h, SPI_PWM_PIN)

        self.encoder = ME.MagneticEncoder(I2C_op)   # assign an angle sensor to the motor


    def update_motor_speed(self, frequency):
        if frequency >= PWM_MAX:
            frequency = PWM_MAX
        elif frequency <= PWM_MIN:
            frequency = PWM_MIN
        lgpio.tx_pwm(h, self.SPI_PWM_PIN, frequency, 50)


    def change_dir(self, dir: int):
        lgpio.gpio_write(h, self.SPI_dir_PIN, dir)


    async def angle_violation(self):
        current_angle = await self.encoder.return_angle()
        if not (MIN_ANGLE <= current_angle and current_angle <= MAX_ANGLE):
            lgpio.tx_pwm(h, self.SPI_PWM_PIN, 0, 50)    # stop motion


    async def initialize_position(self):
        target_angle = self.INIT_ANGLE

        while (True):
            await asyncio.sleep(0.001)
            current_angle = await self.encoder.return_angle()
            error = target_angle - current_angle
            print(error, target_angle, current_angle)

            if (abs(error) <= 1):
                self.update_motor_speed(0)   # stop calibrating
                print("arm ready")
                break

            update_frequency = PID.compute_PID(error)

            if update_frequency <= 0:
                lgpio.gpio_write(h, self.SPI_dir_PIN, 1)
            else:
                lgpio.gpio_write(h, self.SPI_dir_PIN, 0)
            
            self.update_motor_speed(abs(update_frequency))


async def testing():
    testing_motor = Motor(360, 0, 120, 1, 1, 1)
    await testing_motor.initialize_position()

if __name__ == "__main__":
    asyncio.run(testing())