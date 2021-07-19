#ifndef SCU_GPIO_SET_ROS_HPP
#define SCU_GPIO_SET_ROS_HPP

#include <ros/ros.h>
#include <cstdint>

#include "scu_gpio.hpp"
#include "scu_gpio/scu_gpio_cmd.h"

namespace scu_gpio {
    class GpioROS {
        public:
            GpioROS(ros::NodeHandle &nh);

            ~GpioROS();

            void gpioCmdCallback(const scu_gpio_cmd gpio_cmd_msg);
        
        private:
            Gpio gpio_;

            ros::Subscriber gpio_sub_;
    };
}

#endif