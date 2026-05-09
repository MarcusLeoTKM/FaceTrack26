This is a demo

*Always source the shell!*

## Install ROS2

1, Follow: https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html

The installation process takes a while, practice voice articulation while you wait...

2, Run `source /opt/ros/jazzy/setup.bash` to source shell

3, Run `ros2 topic list` to verify installation

4, Install colcon: `sudo apt install colcon`

## Errors 
* If you run into errors (ie. The following packages have unmet dependencies) trying to install ROS2: https://github.com/ros2/ros2/issues/1621#issuecomment-3716728427
* CMake Error: https://stackoverflow.com/questions/31421327/cmake-cxx-compiler-broken-while-compiling-with-cmake

## Typical workflow
*Always have a root directory that contains all the packages.*
- source local shell: `source install/setup.bash`
- create a package (easier when creating a node at the same time). Modify package.xml and setup.py, add entry points
- code stuff
- run `rosdep install -i --from-path src --rosdistro jazzy -y` to make sure there's no missing dependency
- `colcon build --packages-select <package_name>`
- source again `source install/setup.bash`
- `ros2 run <package_name> <executable/node_name>`
