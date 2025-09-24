/*
 * GPIO_devicedriver.c
 *
 *  Created on: Nov 8, 2024
 *      Author: panka
 */
#include <STM32F401RE.h>
#include <GPIO_devicedriver.h>
#include <stdint.h>


void GPIO_init(uint32_t port)
{
	Rcc_reg->AHB1ENR |= (1 << port);
}
void GPIO_config_pin(uint8_t pin, uint32_t port, uint8_t speed, uint8_t mode, uint8_t type, uint8_t pupd)
{
	GPIO_Config_t *GPIO = (GPIO_Config_t*)port;
	GPIO->MODE |= (mode << pin*2);
	GPIO->PUPDR |= (pupd << pin*2);
	GPIO->SPEED |= (speed << pin*2);
	GPIO->TYPE |= (type << pin);
}
void GPIO_config_port(uint8_t speed, uint32_t port, uint8_t mode, uint8_t type, uint8_t pupd)
{
	GPIO_Config_t *GPIO = (GPIO_Config_t*)port;
	for(int pin = 0; pin <= 15; pin++)
	{
		GPIO->MODE |= (mode << pin*2);
		GPIO->PUPDR |= (pupd << pin*2);
		GPIO->SPEED |= (speed << pin*2);
		GPIO->TYPE |= (type << pin);
	}
}
void GPIO_output_pin(uint8_t pin, uint32_t port, uint8_t data)
{
	GPIO_Reg_t *GPIO = (GPIO_Reg_t*)port;
	GPIO->output &= ~(1 << pin);
	GPIO->output |= (data << pin);
}
void GPIO_output_port(uint32_t port, uint32_t data)
{
	GPIO_Reg_t *GPIO = (GPIO_Reg_t*)port;
	GPIO->output |= data; //
}
uint8_t GPIO_input_pin(uint8_t pin, uint32_t port)
{
	GPIO_Reg_t *GPIO = (GPIO_Reg_t*)port;
	uint16_t data = GPIO->input;
	data = data >> pin;
	return (uint8_t)data;
}
uint16_t GPIO_input_port(uint32_t port)
{
	GPIO_Reg_t *GPIO = (GPIO_Reg_t*)port;
	uint16_t data = GPIO->input;
	return data;
}
void GPIO_lock_config(uint32_t port)
{
	GPIO_Reg_t *GPIO = (GPIO_Reg_t*)port;
	GPIO->config_lock |= (0xFFFF << 0);
	GPIO->config_lock |= (1 << 16);
}
void GPIO_alternate_func(uint32_t port, uint8_t pin, uint8_t mode)
{
	int temp = pin/8;
	GPIO_Reg_t *GPIO = (GPIO_Reg_t*)port;
	GPIO->alternate_function[temp] |= (mode << pin*4);
}
