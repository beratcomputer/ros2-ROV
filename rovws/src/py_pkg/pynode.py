#!/usr/bin/env python3 #python interpreteur address 
import rclpy
from rclpy.node import Node
 
 
class MyCustomNode(Node): # class declaretion for node
    def __init__(self):
        super().__init__("node_name") # node initial object attributes declaretion
 
 
def main(args=None): #main function
    rclpy.init(args=args)
    node = MyCustomNode() # node attended to "node" variable
    rclpy.spin(node) #prevent the close terminal after node functions have done
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()