"""
Date: 2026 Apr 27
Magnetic Encoder class

AS5600
Currently, the device is only capable of supporting one encoder at a time due to the limited number of hardware I2C pins on the Pi. 
Later, I will add a I2C switch to allow up to 4 encoder connections.
"""
from smbus2 import SMBus

# same address for every encoder
DEVICE_ADDRESS = 0x36       # The 7-bit address of AS5600
ANGLE_REGISTER = 0x0E       # The ANGLE register which stores 2 Bytes 

ENCODER_RESOLUTION = 4096

class MagneticEncoder:
    def __init__(self, I2C_op):
        if (not I2C_op):
            return  # no sensor needed

        self.I2C_op = I2C_op

    def read_angle(self):       
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

    async def return_angle(self) -> int:
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
    