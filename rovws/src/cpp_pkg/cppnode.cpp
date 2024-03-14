#include "rclcpp/rclcpp.hpp"
 
class MyCustomNode : public rclcpp::Node // class declaretion for node
{
public:
    MyCustomNode() : Node("node_name") //node initial object attributes declaretion
    {
    }
 
private:
};
 
int main(int argc, char **argv) //main function
{
    rclcpp::init(argc, argv);   
    auto node = std::make_shared<MyCustomNode>(); // node attended to "node" variable
    rclcpp::spin(node); //prevent the close terminal after node functions have done
    rclcpp::shutdown();
    return 0;
}