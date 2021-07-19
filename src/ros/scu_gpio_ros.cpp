#include "scu_gpio_ros.hpp"

namespace scu_gpio {
    GpioROS::GpioROS(ros::NodeHandle &nh)
    {
        // GpioROS::gpio_;
        GpioROS::gpio_service_ = nh.advertiseService("gpio", &GpioROS::set_gpio_, this);    }
    
    GpioROS::~GpioROS() {

    }

    // void GpioROS::gpioCmdCallback(const scu_gpio_cmd gpio_cmd_msg) {
    //     GpioROS::gpio_.setup_gpio((int8_t *)&gpio_cmd_msg.BOARD_PIN_SET[0]);
    //     ROS_INFO("PIN_0: %d", gpio_cmd_msg.BOARD_PIN_SET[0]);
    // }

    bool GpioROS::set_gpio_(
    scu_gpio::gpio_cmd_stt::Request &req,
    scu_gpio::gpio_cmd_stt::Response &res) {
        gpio_ctrler.setup_gpio((int8_t *)&req.BOARD_PIN_CMD[0]);
        ROS_INFO("request");
        ROS_INFO("responding..");
        
        for (int pin_index = 0; pin_index <= 40; pin_index++)
            res.BOARD_PIN_STT[pin_index] = gpio_ctrler.gpio_get[pin_index];

        return true;
    }
}