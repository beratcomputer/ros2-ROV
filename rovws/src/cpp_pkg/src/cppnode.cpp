#include "rclcpp/rclcpp.hpp"
 
class CppNode : public rclcpp::Node // Class Decleration
{
public:
    CppNode() : Node("cppnode") // Node name modifying
    {
    }
 
private:
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CppNode>(); // Attended to "node" variable
    rclcpp::spin(node); //Prevent to close the terminal session after the node's functions completed
    rclcpp::shutdown();
    return 0;
}