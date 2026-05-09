This directory uses the template from https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries.html

**2026 May 8**

Install python3, python3-opencv, python3-smbus2, python3-lgpio

You should have custom message types in a seperate package, so that they are easily accessible to other packages.
Once you are done, add the message dependencies into the package.xml file, ie `<exec_depend>message_package_name</exec_depend>`

Tutorial: https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html
