"""
Author: Leo Wang
Date: 2026 Mar 25

Determine motor's orientation

AS5600 Hall Effect Sensor's Datasheet:
    - https://look.ams-osram.com/m/7059eac7531a86fd/original/AS5600-DS000365.pdf
    - https://github.com/kplindegaard/smbus2
    - The sensor's location is at 0x36

Initialize I2C on Pi:
    1. sudo dtparam i2c_arm=on
    2. sudo modprobe i2c-dev

Install smbus2:
    1. sudo apt install python3-smbus2

Find available I2C interfaces:
    1. ls /dev/i2c-*

Find devices connected to a specific I2C interface:
    1. i2cdetect -y 1
"""
from smbus2 import SMBus

DEVICE_ADDRESS = 0x36       # The 7-bit address of AS5600
ANGLE_REGISTER = 0x0E       # The ANGLE register which stores 2 Bytes 

ENCODER_RESOLUTION = 4096

def read_angle():       
    with SMBus(1) as bus:
        """
        Read values from the ANGLE register (12 bit):
            A[11:8] B[7:0]
            AAAABBBBBBBB
        """
        (A_byte, B_byte) = bus.read_i2c_block_data(DEVICE_ADDRESS, ANGLE_REGISTER, 2)
        resolution = (A_byte << 8) | B_byte

        angle = resolution * 360 / ENCODER_RESOLUTION
        print(f"Angle: {angle:,.2f}")


async def return_angle() -> int:
    with SMBus(1) as bus:
        """
        Read values from the ANGLE register (12 bit):
            A[11:8] B[7:0]
            AAAABBBBBBBB
        """
        (A_byte, B_byte) = bus.read_i2c_block_data(DEVICE_ADDRESS, ANGLE_REGISTER, 2)
        resolution = (A_byte << 8) | B_byte

        angle = resolution * 360 / ENCODER_RESOLUTION
        return angle
    
# read_angle()