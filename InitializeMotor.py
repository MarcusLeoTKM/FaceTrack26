"""
Author: Leo Wang
Date: 2026 Mar 25

Initialize motor's starting position
"""
import ControlLogic
import ReadMagneticField as RMF
import PIDTuning as PID


def init():
    PID.move_to_angle(120)

init()