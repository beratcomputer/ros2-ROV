#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberPublisherNode : public rclcpp::Node 
{
public:
    NumberPublisherNode() : Node("number_publisher")    
    {
        this->declare_parameter("number_to_publish" , 2);// aprametre ilanı
        this->declare_parameter("publish_frequency", 1.0);

        number_ = this->get_parameter("number_to_publish").as_int();//parametre atama da böyle yapılıyor
        publish_frequency = this->get_parameter("publish_frequency").as_double();

        number_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        RCLCPP_INFO(this->get_logger(), "number publisher has been started.");
        number_timer_ = this->create_wall_timer(std::chrono::milliseconds((int) (1000.0 / publish_frequency)),
                                         std::bind(&NumberPublisherNode::publishNumber, this));
                                         //periyodu ayarladığımız yerin int olması şartı aranıyor

    }

private:
    
    void publishNumber()
    {
        auto msg = example_interfaces::msg::Int64(); //auto ifadesi msg değişkeninin türünü sağdaki ifadeye bakıp otomatik oalrak belirlenmesini sağlar
        msg.data = number_;
        number_publisher_->publish(msg);
    }

    double publish_frequency;
    int number_;
    rclcpp::TimerBase::SharedPtr number_timer_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;


    
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
