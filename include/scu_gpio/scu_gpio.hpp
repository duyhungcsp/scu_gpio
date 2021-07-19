#ifndef SCU_GPIO_HPP
#define SCU_GPIO_HPP

#include <cstdint>

#define NUMBER_OF_PIN 40

namespace scu_gpio {
    class Gpio {
        public:
            Gpio();
            ~Gpio();

            int8_t gpio_set[NUMBER_OF_PIN + 1];
            int8_t gpio_get[NUMBER_OF_PIN + 1];

            void setup_gpio(int8_t * gpio_setup_p);
            void set_gpio(int8_t * gpio_set_p);
            void get_gpio(int8_t * gpio_get);
    };
}

#endif