## 🪸 Face Tracker 2026

This is a pan-tilt 2 DoF face-tracking camera.

**Project Structure**
* [main.py](main.py): Entry point
* [FaceRecog.py](FaceRecog.py): Detect faces and control the motors
* ~~[ReadMagneticField.py](ReadMagneticField.py): Read angle (Deprecated)~~
* ~~[ControlLogic.py](ControlLogic.py): Motor control (Deprecated)~~
* [classes](classes/)
    * [Motor.py](classes/Motor.py): Hardware abstraction for motor control (SPI/PWM)
    * [MagneticEncoder.py](classes/MagneticEncoder.py): Class for communication with the magnetic encoder
    * [PIDTuning.py](classes/PIDTuning.py): PID tuning logic
