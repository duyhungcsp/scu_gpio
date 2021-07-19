#ifndef SCU_GPIO_ROS_HPP
#define SCU_GPIO_ROS_HPP

#include <ros/ros.h>

#include "scu_gpio_ros.hpp"

namespace scu_gpio {
    class SCU_GPIO_ROS {
        public:
            SCU_GPIO_ROS(ros::NodeHandle &nh);
            ~SCU_GPIO_ROS();

            void run();

        private:
            ros::NodeHandle nh_;
            GpioROS gpio_set_ros_;
    };
}

#endif