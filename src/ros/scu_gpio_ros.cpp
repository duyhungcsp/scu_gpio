#include "scu_gpio_ros.hpp"

namespace scu {
    GpioROS::GpioROS(ros::NodeHandle &nh)
    {
        // GpioROS::gpio_;
        std::thread server_thread(&GpioROS::server_func, this, nh);

        std::thread interrupt_thread(&GpioROS::interrupt_func, this, &gpio_ctrler.gpio_set[0]);

        server_thread.detach();  
    
        interrupt_thread.detach();
    }
    
    GpioROS::~GpioROS() {

    }

    bool GpioROS::set_gpio_(
    scu_gpio::gpio_cmd_stt::Request &req,
    scu_gpio::gpio_cmd_stt::Response &res) {
        for (int pin_index = 1; pin_index <= 40; pin_index++) {
            gpio_ctrler.gpio_set[pin_index] = req.BOARD_PIN_CMD[pin_index];
            ROS_INFO("gpio_set[%d] = %d\n", pin_index, gpio_ctrler.gpio_set[pin_index]);
        }

        gpio_ctrler.setup_gpio((int8_t *)&req.BOARD_PIN_CMD[0]);
        ROS_INFO("request");
        ROS_INFO("responding..");

        for (int pin_index = 1; pin_index <= 40; pin_index++)
            res.BOARD_PIN_STT[pin_index] = gpio_ctrler.gpio_get[pin_index];


        return true;
    }


    /* Thread functions */

    void GpioROS::server_func(ros::NodeHandle nh) {
        GpioROS::gpio_service_ = nh.advertiseService("gpio", &GpioROS::set_gpio_, this);
        ROS_INFO("Running on server..");
        while(true) {
            ros::Rate(1000).sleep();
        }
    }

    void GpioROS::interrupt_func(int8_t * gpio_interrupt_p) {
        int8_t gpio_get_pre[41] = {};
        for (int pin_index = 1; pin_index <= 40; pin_index++) {
            gpio_get_pre[pin_index] = gpio_ctrler.gpio_get[pin_index];
            ROS_INFO("%d\n", gpio_ctrler.gpio_get[pin_index]);
        }

        while (true) {
            gpio_ctrler.get_gpio(gpio_interrupt_p);
            for (int pin_index = 1; pin_index <= 40; pin_index++) {
                if ((gpio_ctrler.gpio_get[pin_index] != 2) && (gpio_get_pre[pin_index] != gpio_ctrler.gpio_get[pin_index])) {
                    ROS_INFO("change on PIN %d.\n", pin_index);
                }

            }

            for (int pin_index = 0; pin_index <= 40; pin_index++) {
                // ROS_INFO("gpio_get_pre[%d] = %d\n", pin_index, gpio_get_pre[pin_index]);
                gpio_get_pre[pin_index] = gpio_ctrler.gpio_get[pin_index];
            }

            ros::Rate(100).sleep();
            // ROS_INFO("Running on routine..");
        }
    }

}