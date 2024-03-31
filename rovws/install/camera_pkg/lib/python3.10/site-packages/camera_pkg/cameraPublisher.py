#!/usr/bin/env python3

import cv2

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge



 
 
class CameraPublisherNode(Node): 
    
    def __init__(self):
        #üst sınıfın atıflarını çalıştırır
        super().__init__("camera_pub") 
        
        #burada donanıma bağlı bulunan kamera nuarmasını seçiyoruz
        #bu sayı linux'un kameraya atadığı sayıya bağlıdır
        self.cameraDeviceNumber = 2
        self.camera = cv2.VideoCapture(self.cameraDeviceNumber)
        #opencv image'lerini ROS mesaj tipine dönüştürmemizi sağlayan nesnemiz
        self.bridgeObject = CvBridge()
        #veriyi yollayacağımız topic adı
        self.topicNamesFrames = "topic_camera_image"
        #buffer size for storing image
        self.queueSize = 20
        #publisher nesnemiz
        self.publisher = self.create_publisher(Image, self.topicNamesFrames , self.queueSize)
        #period in seconds
        self.periodCommunication = 0.001
        #timer that calls the timer_CallbackFunction with determined time
        self.timer = self.create_timer(self.periodCommunication, self.timer_CallbackFunction)
        #her bir kamera veriyi yollandığında bir artacak
        self.i = 0
    #callBack fonksiyonumuz
    def timer_CallbackFunction(self):
        #kameradaki frame'leri okuyan ve bunu doğrulayan nesnelerimiz
        success , frame = self.camera.read()
        #resize the image
        frame= cv2.resize(frame , (820,640), interpolation=cv2.INTER_CUBIC)
        #kameradaki frame okunuyor ise
        if success == True:
            #burada OpnCV formatındaki görüntüyü ROS mesaj tipine dönüştürüyoruz
            ROSImageMessage = self.bridgeObject.cv2_to_imgmsg(frame)
            #görüntüyü yayınlıyoruz
            self.publisher.publish(ROSImageMessage)
        #terminale mesajın yayınlandığını yazıyoruz
        self.get_logger().info("Publishing image number %d" % self.i )
        
        self.i += 1
 
#main function
def main(args=None):
    #rclpy ı başlatır
    rclpy.init(args=args)
    #Node umuzu başlatır
    node = CameraPublisherNode()
    #node un tekrar etmesini sağlar
    rclpy.spin(node)
    #node durdurulunca tamamen kapatır
    node.destroy_node()
    #rclpy kapatır
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()


