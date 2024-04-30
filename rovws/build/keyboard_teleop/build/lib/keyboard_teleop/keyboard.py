#!/usr/bin/env python3
import sys
import threading

import geometry_msgs.msg
import rclpy

if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty


msg = """
This node takes keypresses from the keyboard and publishes them
as Twist/TwistStamped messages. It works best with a US keyboard layout.
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >

t : up (+z)
b : down (-z)

anything else : stop

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%

CTRL-C to quit
"""

moveBindings = {
    'h': (1, 0, 0, 0, 0, 0), #x art
    'b': (-1, 0, 0, 0, 0, 0),#x az
    'j': (0, 1, 0, 0, 0, 0),#y art
    'n': (0, -1, 0, 0, 0, 0),#y az
    'k': (0, 0, 1, 0, 0, 0),#z art
    'm': (0, 0, -1, 0, 0, 0),#z az
    'H': (0, 0, 0, 1, 0, 0),#x-th art
    'B': (0, 0, 0, -1, 0, 0),#x-th az
    'J': (0, 0, 0, 0, 1, 0),#y-th art
    'N': (0, 0, 0, 0, -1, 0),#y-th az
    'K': (0, 0, 0, 0, 0, 1),#z-th art
    'M': (0, 0, 0, 0, 0, -1),#z-th az
}

speedBindings = {
    'q': (1.1, 1.1),    
    'z': (.9, .9),
    'w': (1.1, 1),
    'x': (.9, 1),
    'e': (1, 1.1),
    'c': (1, .9),
}


def getKey(settings):
    if sys.platform == 'win32':
        # getwch() returns a string on Windows
        key = msvcrt.getwch()
    else:
        tty.setraw(sys.stdin.fileno())
        # sys.stdin.read() returns a string on Linux
        key = sys.stdin.read(1)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)


def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)


def vels(speed, turn):
    return 'currently:\tspeed %s\tturn %s ' % (speed, turn)


def main():
    settings = saveTerminalSettings()

    rclpy.init()

    node = rclpy.create_node('teleop_twist_keyboard')

    # parameters
    stamped = node.declare_parameter('stamped', False).value
    frame_id = node.declare_parameter('frame_id', '').value
    if not stamped and frame_id:
        raise Exception("'frame_id' can only be set when 'stamped' is True")

    if stamped:
        TwistMsg = geometry_msgs.msg.TwistStamped
    else:
        TwistMsg = geometry_msgs.msg.Twist

    pub = node.create_publisher(TwistMsg, 'cmd_vel', 10)

    spinner = threading.Thread(target=rclpy.spin, args=(node,))
    spinner.start()

    speed = 1.0
    turn = 1.0
    x = 0.0
    y = 0.0
    z = 0.0
    th_x = 0.0
    th_y = 0.0
    th_z = 0.0
    status = 0.0

    twist_msg = TwistMsg()

    if stamped:
        twist = twist_msg.twist
        twist_msg.header.stamp = node.get_clock().now().to_msg()
        twist_msg.header.frame_id = frame_id
    else:
        twist = twist_msg

    try:
        print(msg)
        print(vels(speed, turn))
        while True:
            key = getKey(settings)
            if key in moveBindings.keys():
                x += moveBindings[key][0]*100
                y += moveBindings[key][1]*100
                z += moveBindings[key][2]*100
                th_x += moveBindings[key][3]*100
                th_y += moveBindings[key][4]*100
                th_z += moveBindings[key][5]*100
            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
                turn = turn * speedBindings[key][1]

                print(vels(speed, turn))
                if (status == 14):
                    print(msg)
                status = (status + 1) % 15
            else:
                x = 0.0
                y = 0.0
                z = 0.0
                th_x = 0.0
                th_y = 0.0
                th_z = 0.0
                if (key == '\x03'):
                    break

            if x >1000:
                x = 1000.0
            if y >1000:
                y = 1000.0
            if z >1000:
                z = 1000.0
            if th_x >1000:
                th_x = 1000.0
            if th_y >1000:
                th_y = 1000.0
            if th_z >1000:
                th_z = 1000.0
                
            if x <-1000:
                x = -1000.0
            if y <-1000:
                y = -1000.0
            if z <-1000:
                z = -1000.0
            if th_x <-1000:
                th_x = -1000.0
            if th_y <-1000:
                th_y = -1000.0
            if th_z <-1000:
                th_z = -1000.0
                

            if stamped:
                twist_msg.header.stamp = node.get_clock().now().to_msg()

            twist.linear.x = x * speed
            twist.linear.y = y * speed
            twist.linear.z = z * speed
            twist.angular.x = th_x * turn
            twist.angular.y = th_y * turn
            twist.angular.z = th_z * turn
            pub.publish(twist_msg)

    except Exception as e:
        print(e)

    finally:
        if stamped:
            twist_msg.header.stamp = node.get_clock().now().to_msg()

        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0
        pub.publish(twist_msg)
        rclpy.shutdown()
        spinner.join()

        restoreTerminalSettings(settings)


if __name__ == '__main__':
    main()