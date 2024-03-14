#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
 
 
class PyNode(Node): # Class Decleration     
    def __init__(self):
        super().__init__("pynode") # Node name modifying
 
 
def main(args=None):
    rclpy.init(args=args)
    node = PyNode() # Attended to "node" variable
    rclpy.spin(node) # Prevent to close the terminal session after the node's functions completed
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()