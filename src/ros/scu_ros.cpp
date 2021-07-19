#include "scu_ros.hpp"

namespace scu_gpio {
    SCU_GPIO_ROS::SCU_GPIO_ROS(ros::NodeHandle &nh) :
    nh_(nh),
    gpio_set_ros_(nh) 
    {

    }
    SCU_GPIO_ROS::~SCU_GPIO_ROS() {

    }

    void SCU_GPIO_ROS::run() {
        
    }

}

int main(int argc, char **argv) {
    ros::init(argc, argv, "scu_gpio_ros");
    ros::NodeHandle nh;
    scu_gpio::SCU_GPIO_ROS scu_gpio_ros_(nh);
    // scu_gpio_ros_.run();
    ros::spin();
}