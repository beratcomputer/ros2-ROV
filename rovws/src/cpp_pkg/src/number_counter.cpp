#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"
#include "rclcpp/rclcpp.hpp"

class NumberCounterNode : public rclcpp::Node
{

public:
    NumberCounterNode() : Node("number_counter"), counter_(0)
    {
        counter_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        RCLCPP_INFO(this->get_logger(), "number counter has been started.");

        number_subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
            "number", 10, std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1));

        //reset_counter_service_ = this->create_service<example_interfaces::srv::SetBool>("reset_counter", 
        //10, std::bind(&NumberCounterNode::callbackResetCounter, 
        //this, std::placeholders::_1,_2));
    }

private:
    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        counter_ += msg->data;
        auto newMsg = example_interfaces::msg::Int64();
        newMsg.data = counter_;
        counter_publisher_->publish(newMsg);
    }

    /*void callbackResetCounter(const example_interfaces::srv::SetBool::Request::SharedPtr request,
                              const example_interfaces::srv::SetBool::Response::SharedPtr response)
    {

        if (request->data == true)
        {
            this->counter_ = 0;
            response->success = true;
            response->message = "Counter has been reset";
        }
        else
        {
            response->success = false;
            response->message = "Counter has NOT been reset";
        }
        return response
    }*/

    int counter_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr counter_publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr number_subscriber_;
    //rclcpp::Service;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}