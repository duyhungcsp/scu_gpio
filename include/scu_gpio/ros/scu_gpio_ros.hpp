#ifndef SCU_GPIO_SET_ROS_HPP
#define SCU_GPIO_SET_ROS_HPP

#include <ros/ros.h>
#include <cstdint>
#include <thread>

#include "scu_gpio.hpp"
#include "scu_gpio/scu_gpio_cmd.h"
#include "scu_gpio/gpio_cmd_stt.h"

namespace scu {
    class GpioROS {
        public:
            GpioROS(ros::NodeHandle &nh);

            ~GpioROS();

            bool set_gpio_(
                scu_gpio::gpio_cmd_stt::Request &req,
                scu_gpio::gpio_cmd_stt::Response &res);

            void server_func(ros::NodeHandle nh);

            void interrupt_func(int8_t * gpio_interrupt_p);

        private:

            scu::Gpio gpio_ctrler;

            ros::ServiceServer gpio_service_;
    };

    // void interrupt_func(int pin_index);
}

#endif