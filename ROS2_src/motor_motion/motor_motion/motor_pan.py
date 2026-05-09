"""
2026 May 9

The pan motor node 
"""
import rclpy
from rclpy.node import Node
from messages.msg import OffsetPX   # import message type OffsetPX 

from std_msgs.msg import String

class CameraSubscriber(Node):
    def __init__(self):
        super().__init__('motor_pan')
        self.subscription = self.create_subscription(
            OffsetPX,
            'horizontal_offset_px',    # topic name has to match the publisher's topic name
            self.listener_callback,    # listener_callback() gets called when there's a new message 
            10)
        self.subscription  

    def listener_callback(self, msg):
        self.get_logger().info('New offset pixel: "%.2f"' % msg.offset_px)


def main(args=None):
    rclpy.init(args=args)

    camera_subscriber = CameraSubscriber()

    rclpy.spin(camera_subscriber)

    camera_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()