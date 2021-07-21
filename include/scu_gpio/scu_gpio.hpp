#ifndef SCU_GPIO_HPP
#define SCU_GPIO_HPP

#include <cstdint>

#define NUMBER_OF_PIN 40

namespace scu{
// namespace scu_gpio {
    class Gpio {
        public:
            Gpio();
            ~Gpio();

            uint8_t gpio_set[NUMBER_OF_PIN + 1];
            uint8_t gpio_get[NUMBER_OF_PIN + 1];
            // int8_t gpio_event[NUMBER_OF_PIN + 1];

            // void check_pin_setup(int8_t * gpio_set_pre_p, int8_t * gpio_set_p);
            void setup_gpio(uint8_t * gpio_set_pre_p, uint8_t * gpio_setup_p);
            void set_gpio(uint8_t * gpio_set_p);
            void get_gpio(uint8_t * gpio_get_p);
            // void change_on_gpio(int8_t * gpio_p);
    };
// }
}

#endif