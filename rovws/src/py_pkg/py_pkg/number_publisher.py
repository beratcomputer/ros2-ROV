#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int32
 
class NumberPublisherNode(Node): 
    def __init__(self):
        super().__init__("number_publisher")
        self.declare_parameter("number_to_publish",10)#aprametre ilanı böyle yapılıyor. 
        #buradaki 2 eğer terminalden bir aprametre girişi yapılmazsa kullanıalcak olan default parametredir
        self.declare_parameter("publish_frequency",1.0)
        self.publish_frequency_ =self.get_parameter("publish_frequency").value
        


        #self.number_ = 2 #burası, aprametre kullanmadan önceki kod parçasıydı
        self.number_=self.get_parameter("number_to_publish").value#aprametreyi yerel değişkene böyle atıyoruz
        self.number_publisher_=self.create_publisher(Int32, "number",10)

        self.number_timer_=self.create_timer(1.0/self.publish_frequency_ , self.publish_number)#1.0/frequency yaptık çünkü o ifade periyodu temsil ediyor.
        


        self.get_logger().info("number publisher has been started")
        #self.publish_number()

    def publish_number(self):
        msg = Int32()
        msg.data = self.number_
        self.number_publisher_.publish(msg)




def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()