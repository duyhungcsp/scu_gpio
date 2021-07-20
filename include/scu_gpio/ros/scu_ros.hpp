#ifndef SCU_GPIO_ROS_HPP
#define SCU_GPIO_ROS_HPP

#include <ros/ros.h>
#include <thread>

#include "scu_gpio_ros.hpp"

// using namespace std;

namespace scu {
    class SCU_ROS {
        public:
            SCU_ROS(ros::NodeHandle &nh);
            ~SCU_ROS();

            void run();

        private:
            ros::NodeHandle nh_;
            GpioROS gpio_set_ros_;
    };

    // std::thread gpio_interrupt_thread;

    // void gpio_interrupt_func(int pin_index);
}

#endif