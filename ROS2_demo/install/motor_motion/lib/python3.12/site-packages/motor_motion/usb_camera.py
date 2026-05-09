"""
2026 May 9

The USB camera node 
Template: https://docs.ros.org/en/jazzy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Publisher-And-Subscriber.html
"""

import rclpy
from rclpy.node import Node
from messages.msg import OffsetPX   # import message type OffsetPX 

from std_msgs.msg import String


class CameraPublisher(Node):
    def __init__(self):
        super().__init__('usb_camera')  # node name: "usb_camera"
        self.publisher_ = self.create_publisher(OffsetPX, 'horizontal_offset_px', 10)    # topic name: "horizontal_offset_px", message type: String
        
        # -- publish messages every 0.5 seconds -- (optional)
        timer_period = 0.5 
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = OffsetPX()
        msg.offset_px = 180.22
        # msg.data = 'Counting: %d' % self.i
        self.publisher_.publish(msg)    # publish msg.data
        print(msg.offset_px)
        # self.get_logger().info('Publishing: "%s"' % msg.data)
        # self.i += 1


def main(args=None):
    rclpy.init(args=args)

    camera_publisher = CameraPublisher()

    rclpy.spin(camera_publisher)   # start the node 

    camera_publisher.destroy_node()    # destroy the node
    rclpy.shutdown()


if __name__ == '__main__':
    main()