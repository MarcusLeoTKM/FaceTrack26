from setuptools import find_packages, setup

package_name = 'motor_motion'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='feige',
    maintainer_email='leowang657@gmail.com',
    description='Control for the motors and input from the camera',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'motor_pan = motor_motion.motor_pan:main',
            'usb_camera = motor_motion.usb_camera:main'
        ],
    },
)
