#include <iostream>
#include "JetsonGPIO.h"
#include "scu_gpio.hpp"

using namespace std;

namespace scu{
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

    // /* Check GPIO pins are setup or not. */
    // void Gpio::check_pin_setup(uint8_t * gpio_set_pre_p, uint8_t * gpio_set_p) {
    //     for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++) {
    //         switch (pin_index) {
    //             /* Skip these pins cause they are not GPIO pins. */
    //             case 1:     // 3.3 VDC
    //             case 2:     // 5.0 VDC
    //             case 3:     // I2C1_SDA
    //             case 4:     // 5.0 VDC
    //             case 5:     // I2C1_SCL
    //             case 6:     // GND
    //             case 8:     // UART1_TX
    //             case 9:     // GND
    //             case 10:    // UART1_RX
    //             case 14:    // GND
    //             case 17:    // 3.3 VDC
    //             case 20:    // GND
    //             case 25:    // GND
    //             case 27:    // I2C0_SDA
    //             case 28:    // I2C0_SCL
    //             case 30:    // GND
    //             case 34:    // GND
    //             case 39:    // GND
    //                 break;
    //             default:
    //                 switch (gpio_setup_p[pin_index]) {
    //                     case 0xFC:
    //                         break;
    //                     case 0x10:
    //                         if (gpio_pre_p[pin_index] != 0x10)

    // }

    /* Configure GPIO list of pins as this rules:
     *   BOARD_PIN_CMD[x] = 0xFC: unchange
     *   BOARD_PIN_CMD[x] = 0x10: output LOW
     *   BOARD_PIN_CMD[x] = 0x11: output HIGHT
     *   BOARD_PIN_CMD[x] = 0x0F: input
     *   BOARD_PIN_CMD[x] = 0x0A: input attach Interrupt RISING edge
     *   BOARD_PIN_CMD[x] = 0x0B: input attach Interrupt FALLING edge
     *   BOARD_PIN_CMD[x] = 0x0C: input attach Interrupt onchange
     *   BOARD_PIN_CMD[x] = 0xFA: alternative function
        * Pin number 1 to 40 (skip index 0)
    */
    void Gpio::setup_gpio(uint8_t * gpio_set_pre_p, uint8_t * gpio_setup_p) {
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
                        case 0xFC:
                            break;
                        case 0x10:
                            if (gpio_set_pre_p[pin_index] != 0x10)
                                GPIO::setup(pin_index, GPIO::OUT, GPIO::LOW);
                            break;
                        case 0x11:
                            if (gpio_set_pre_p[pin_index] != 0x11)
                                GPIO::setup(pin_index, GPIO::OUT, GPIO::HIGH);
                            break;
                        case 0x0F:
                            if (gpio_set_pre_p[pin_index] != 0x0F)
                                GPIO::setup(pin_index, GPIO::IN);
                            Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            break;
                        case 0x0A:
                            if (gpio_set_pre_p[pin_index] != 0x0A) {
                                GPIO::setup(pin_index, GPIO::IN);
                                Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            }
                            break;
                        case 0x0B:
                            if (gpio_set_pre_p[pin_index] != 0x0B) {
                                GPIO::setup(pin_index, GPIO::IN);
                                Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            }
                            break;
                        case 0x0C:
                            if (gpio_set_pre_p[pin_index] != 0x0C) {
                                GPIO::setup(pin_index, GPIO::IN);
                                Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            }
                            break;   
                        default:       
                            break;                    
                    }
                    break;
            }  
            if (gpio_setup_p[pin_index] != 0xFC)
                gpio_set_pre_p[pin_index] = (uint8_t)gpio_setup_p[pin_index];  
        }
    }

    /* Set GPIO pin out:
        *   BOARD_PIN_SET[x] = 0: output LOW
        *   BOARD_PIN_SET[x] = 1: output HIGHT
    */
    void Gpio::set_gpio(uint8_t * gpio_set_p) {
        /* Firstly, setup GPIO. */
        Gpio::setup_gpio(&Gpio::gpio_set[0], gpio_set_p);

        /* Secondly, assign output value. */
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
                        case 0xFC:
                            break;
                        case 0x10:
                            GPIO::output(pin_index, GPIO::LOW);
                            break;
                        case 0x11:
                            GPIO::output(pin_index, GPIO::HIGH);
                            break;
                        case 0x0F:
                            break;
                        default:       
                            break;                    
                    }
                    break;
            }    
        }
    }

    /* Get GPIO pin input:
        *   BOARD_PIN_GET[x] = 0x00: input LOW
        *   BOARD_PIN_GET[x] = 0x01: input HIGHT
        *   BOARD_PIN_GET[x] = 0x02: not input pin
    */
    void Gpio::get_gpio(uint8_t * gpio_get_p) {
        /* Firstly, setup GPIO. */
        Gpio::setup_gpio(&Gpio::gpio_set[0], gpio_get_p);

        /* Secondly, get input value. */
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
                    Gpio::gpio_get[pin_index] = 0x02;
                    break;

                /* Setup these GPIO pins. */
                default:
                    switch (gpio_get_p[pin_index]) {
                        case 0x0A:
                            Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            break;
                        case 0x0B:
                            Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            break;
                        case 0x0C:
                            Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            break;
                        case 0x0F:
                            Gpio::gpio_get[pin_index] = GPIO::input(pin_index);
                            break;
                        default:  
                            Gpio::gpio_get[pin_index] = 0x02;
                            break;                    
                    }
                    break;
            }    
        }
    }

    // /* Get GPIO pin change event input:
    //  * BOARD_PIN_STT[x] = 0x0A: input attach Interrupt RISING edge
    //  * BOARD_PIN_STT[x] = 0x0B: input attach Interrupt FALLING edge
    //  * BOARD_PIN_STT[x] = 0x0C: input attach Interrupt onchange
    //  * BOARD_PIN_STT[x] = 0x0F: input no event
    // */    

    // void Gpio::change_on_gpio(uint8_t * gpio_p) {
    //     /* Firstly, setup GPIO. */
    //     Gpio::setup_gpio(gpio_set_p);

    //     /* Secondly, check GPIO interrupt. */        
    //     for (int pin_index = 1; pin_index <= NUMBER_OF_PIN; pin_index++) {
    //         switch (pin_index) {
    //             /* Skip these pins because they are not GPIO pins. */
    //             case 1:     // 3.3 VDC
    //             case 2:     // 5.0 VDC
    //             case 3:     // I2C1_SDA
    //             case 4:     // 5.0 VDC
    //             case 5:     // I2C1_SCL
    //             case 6:     // GND
    //             case 8:     // UART1_TX
    //             case 9:     // GND
    //             case 10:    // UART1_RX
    //             case 14:    // GND
    //             case 17:    // 3.3 VDC
    //             case 20:    // GND
    //             case 25:    // GND
    //             case 27:    // I2C0_SDA
    //             case 28:    // I2C0_SCL
    //             case 30:    // GND
    //             case 34:    // GND
    //             case 39:    // GND
    //                 Gpio::gpio_get[pin_index] = 0x0F;
    //                 break;

    //             /* Setup these GPIO pins. */
    //             default:
    //                 switch (gpio_p[pin_index]) {
    //                     case 0x0A:
    //                         if ((Gpio::gpio_get[pin_index] == 0x00) && GPIO::input(pin_index) == 0x01))
    //                             Gpio::gpio_event[pin_index] = 0x0A;
    //                         else
    //                             Gpio::gpio_event[pin_index] = 0x0F;
    //                         break;
    //                     default:  
    //                         Gpio::gpio_get[pin_index] = 0x0F;
    //                         break;                    
    //                 }
    //                 break;
    //         }    
    //     }
    // }
}