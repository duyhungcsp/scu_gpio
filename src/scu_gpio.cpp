#include <iostream>
#include "JetsonGPIO.h"
#include "scu_gpio.hpp"

using namespace std;

namespace scu_gpio {
    /* Init GPIO in pin BOARD mode. */
    Gpio::Gpio() {
        /* Set GPIO pins in BOARD mode from 1 to 40. */
        GPIO::setmode(GPIO::BOARD);

        /* Init value for input pins. */
        for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++)
            Gpio::gpio_get[pin_index] = 0;
    }

    /* Clean all GPIO pins at the end of program. */
    Gpio::~Gpio() {
        for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++)
            switch (pin_index) {
                /* Skip these pins cause they are not GPIO pins. */
                case 1:     // 3.3 VDC
                case 2:     // 5.0 VDC
                case 3:     // I2C1_SDA
                case 4:     // 5.0 VDC
                case 5:     // I2C1_SCL
                case 6:     // GND
                case 8:     // UART1_TX
                case 9:     // GND
                case 10:    // UART1_RX
                case 14:    // GND
                case 17:    // 3.3 VDC
                case 20:    // GND
                case 25:    // GND
                case 27:    // I2C0_SDA
                case 28:    // I2C0_SCL
                case 30:    // GND
                case 34:    // GND
                case 39:    // GND
                    break;

                /* Clean these GPIO pins. */    
                default:               
                    GPIO::cleanup(pin_index);
                    break;
            }
    }

    /* Configure GPIO list of pins as this rules:
        *   BOARD_PIN_SET[x] is set with different values corresponding to different status:
        *   BOARD_PIN_SET[x] = -1: unchange
        *   BOARD_PIN_SET[x] = 0: output LOW
        *   BOARD_PIN_SET[x] = 1: output HIGHT
        *   BOARD_PIN_SET[x] = 2: input
        *   BOARD_PIN_SET[x] = 3: alternative function
        * Pin number 1 to 40 (skip index 0)
    */
    void Gpio::setup_gpio(int8_t * gpio_setup_p) {
        for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++) {
            switch (pin_index) {
                /* Skip these pins cause they are not GPIO pins. */
                case 1:     // 3.3 VDC
                case 2:     // 5.0 VDC
                case 3:     // I2C1_SDA
                case 4:     // 5.0 VDC
                case 5:     // I2C1_SCL
                case 6:     // GND
                case 8:     // UART1_TX
                case 9:     // GND
                case 10:    // UART1_RX
                case 14:    // GND
                case 17:    // 3.3 VDC
                case 20:    // GND
                case 25:    // GND
                case 27:    // I2C0_SDA
                case 28:    // I2C0_SCL
                case 30:    // GND
                case 34:    // GND
                case 39:    // GND
                    break;

                /* Setup these GPIO pins. */
                default:
                    switch (gpio_setup_p[pin_index]) {
                        case -1:
                            break;
                        case 0:
                            GPIO::setup(pin_index, GPIO::OUT, GPIO::LOW);
                            break;
                        case 1:
                            GPIO::setup(pin_index, GPIO::OUT, GPIO::HIGH);
                            break;
                        case 2:
                            GPIO::setup(pin_index, GPIO::IN);
                            break;
                        default:       
                            break;                    
                    }
                    break;
            }    
        }
    }

    /* Set GPIO pin out:
        *   BOARD_PIN_SET[x] = 0: output LOW
        *   BOARD_PIN_SET[x] = 1: output HIGHT
    */
    void Gpio::set_gpio(int8_t * gpio_set_p) {
        for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++) {
            switch (pin_index) {
                /* Skip these pins cause they are not GPIO pins. */
                case 1:     // 3.3 VDC
                case 2:     // 5.0 VDC
                case 3:     // I2C1_SDA
                case 4:     // 5.0 VDC
                case 5:     // I2C1_SCL
                case 6:     // GND
                case 8:     // UART1_TX
                case 9:     // GND
                case 10:    // UART1_RX
                case 14:    // GND
                case 17:    // 3.3 VDC
                case 20:    // GND
                case 25:    // GND
                case 27:    // I2C0_SDA
                case 28:    // I2C0_SCL
                case 30:    // GND
                case 34:    // GND
                case 39:    // GND
                    break;

                /* Setup these GPIO pins. */
                default:
                    switch (gpio_set_p[pin_index]) {
                        case -1:
                            break;
                        case 0:
                            GPIO::output(pin_index, GPIO::LOW);
                            break;
                        case 1:
                            GPIO::output(pin_index, GPIO::HIGH);
                            break;
                        case 2:
                            break;
                        default:       
                            break;                    
                    }
                    break;
            }    
        }
    }

    /* Get GPIO pin out:
        *   BOARD_PIN_SET[x] = 0: input LOW
        *   BOARD_PIN_SET[x] = 1: input HIGHT
    */
    void Gpio::get_gpio(int8_t * gpio_set_p) {
        for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++) {
            switch (pin_index) {
                /* Skip these pins because they are not GPIO pins. */
                case 1:     // 3.3 VDC
                case 2:     // 5.0 VDC
                case 3:     // I2C1_SDA
                case 4:     // 5.0 VDC
                case 5:     // I2C1_SCL
                case 6:     // GND
                case 8:     // UART1_TX
                case 9:     // GND
                case 10:    // UART1_RX
                case 14:    // GND
                case 17:    // 3.3 VDC
                case 20:    // GND
                case 25:    // GND
                case 27:    // I2C0_SDA
                case 28:    // I2C0_SCL
                case 30:    // GND
                case 34:    // GND
                case 39:    // GND
                    break;

                /* Setup these GPIO pins. */
                default:
                    switch (gpio_set_p[pin_index]) {
                        case -1:
                            break;
                        case 0:
                            GPIO::input(pin_index);
                            break;
                        case 1:
                            GPIO::input(pin_index);
                            break;
                        case 2:
                            break;
                        default:       
                            break;                    
                    }
                    break;
            }    
        }
    }
}