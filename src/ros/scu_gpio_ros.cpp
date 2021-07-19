#include "scu_gpio_ros.hpp"

namespace scu_gpio {
    GpioROS::GpioROS(ros::NodeHandle &nh) :
    gpio_()
    {
        GpioROS::gpio_sub_ = nh.subscribe("scu_gpio_cmd", 1000, &GpioROS::gpioCmdCallback, this);
    }
    
    GpioROS::~GpioROS() {

    }

    void GpioROS::gpioCmdCallback(const scu_gpio_cmd gpio_cmd_msg) {
        GpioROS::gpio_.setup_gpio((int8_t *)&gpio_cmd_msg.BOARD_PIN_SET[0]);
        ROS_INFO("PIN_0: %d", gpio_cmd_msg.BOARD_PIN_SET[0]);
    }
}