#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from my_robot_interfaces.msg import Pixhawk
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

import time
from pymavlink import mavutil

# Seri bağlantı portu ve baud oranı
port = '/dev/ttyACM0'  # Seri portunu uygun şekilde değiştirin
baud = 57600  # Baud oranını uygun şekilde değiştirin

# MAVLink bağlantısını oluştur gerekli ayarlamalari yap.
master = mavutil.mavlink_connection(port, baud=baud)
print(master.wait_heartbeat())
master.set_mode_manual()
master.mav.command_long_send(master.target_system,master.target_component, mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM , 0, 1, 0, 0, 0, 0, 0,0)





class PixhawkPublisher(Node):
    def __init__(self):
        super().__init__("pixhawk_pub")
        self.set_x = 0
        self.set_y = 0
        self.set_z = 0
        self.set_ang_x = 0
        self.set_ang_y = 0
        self.set_ang_z = 0

        self.declare_parameter("publish_frequency",30.0)
        self.publish_frequency_ =self.get_parameter("publish_frequency").value
        self.number_publisher_=self.create_publisher(Pixhawk, "pixhawk_pub",10)
        self.number_timer_=self.create_timer(1.0/self.publish_frequency_ , self.publishInfo)#1.0/frequency yaptık çünkü o ifade periyodu temsil ediyor.
        self.subscriber_ = self.create_subscription(Twist, 'cmd_vel',self.get_vector, 10)
        #self.subscriber_ = self.create_subscription(Joy, 'joy',self.get_vector, 10)
        self.get_logger().info("Pixhawk Publisher has been started")

    def publishInfo(self):
        msg = master.recv_match(type='ATTITUDE', blocking=True)
        master.mav.manual_control_send(master.target_system, x=self.set_x, y=self.set_y, z=self.set_z, r=0, buttons=0)
        msg_Pixhawk = Pixhawk()

        msg_Pixhawk.roll = msg.roll
        msg_Pixhawk.pitch = msg.pitch
        msg_Pixhawk.yaw = msg.yaw
        #print("Roll: {0} ,Pitch: {1} ,Yaw: {2} ".format(msg_Pixhawk.roll , msg_Pixhawk.pitch , msg_Pixhawk.yaw) )
        self.number_publisher_.publish(msg_Pixhawk)
    def get_vector(self,vector1:Twist):
        self.set_x = int(vector1.linear.x)
        self.set_y = int(vector1.linear.y)
        self.set_z = int(vector1.linear.z)
        self.set_ang_x = vector1.angular.x
        self.set_ang_y = vector1.angular.y
        self.set_ang_z = vector1.angular.z
        print(f"parameters: {self.set_x} , {self.set_y} , {self.set_z}")

        
        
        



def main(args=None):
    rclpy.init(args=args)
    node = PixhawkPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
