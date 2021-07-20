#include "scu_ros.hpp"

namespace scu {
    SCU_ROS::SCU_ROS(ros::NodeHandle &nh) :
    nh_(nh),
    gpio_set_ros_(nh) 
    {

    }
    SCU_ROS::~SCU_ROS() {

    }

    void SCU_ROS::run() {
        // scu::gpio_interrupt_thread = std::thread(std::bind(&scu::gpio_interrupt_func, this), 31);
        // scu::gpio_interrupt_thread.detach();
    }

}

int main(int argc, char **argv) {
    ros::init(argc, argv, "scu_gpio_ros");
    ros::NodeHandle nh;
    scu::SCU_ROS scu_ros_(nh);
    scu_ros_.run();

    ros::spin();
}