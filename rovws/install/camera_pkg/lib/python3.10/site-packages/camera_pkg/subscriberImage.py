#!/usr/bin/env python3
import cv2

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
 
class SubscriberNode(Node): 
    def __init__(self):
        #üst sınıfın atıflarını çalıştırır
        super().__init__("camera_sub") 
        #opencv image'lerini ROS mesaj tipine dönüştürmemizi sağlayan nesnemiz
        self.bridgeObject = CvBridge()
        #veriyi alacağımız topic adı
        self.topicNameFrames = "topic_camera_image"
        #buffer size for storing image
        self.queueSize = 20
        #abonelik nesnemiz
        self.subscription = self.create_subscription(Image, self.topicNameFrames , self.listener_callbackFunction , self.queueSize)
        self.subscription #This is used to prevent unused variable warning (bu yöntemi ilk defa görüyorum)
    #calllback fonksiyonumuz   
    def listener_callbackFunction(self, imageMessage):
        #terminale bilgilendirme mesajı yazdırır
        self.get_logger().info("The image frame is received")
        #ROS mesaj tipini opencv görüntüsüne dönüştürür
        openCVImage = self.bridgeObject.imgmsg_to_cv2(imageMessage)
        #görüntüyü ekranda gösterir, string verisi içinde pencere adını
        cv2.imshow("Camera video" , openCVImage)
        #görüntüyü açan pencerenin görüntü gidince kapanmasını sağlar
        cv2.waitKey(1)
        
#main function
    
def main(args=None):
    #rclpy ı başlatır
    rclpy.init(args=args)
    #Node umuzu başlatır
    node = SubscriberNode() 
    #node un tekrar etmesini sağlar  
    rclpy.spin(node)
    #node durdurulunca tamamen kapatır
    node.destroy_node()
    #rclpy kapatır
    rclpy.shutdown()
 
if __name__ == "__main__":
    main()
