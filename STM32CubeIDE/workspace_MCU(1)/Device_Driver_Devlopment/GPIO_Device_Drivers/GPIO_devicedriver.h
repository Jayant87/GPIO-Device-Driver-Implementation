/*
 * GPIO_devicedriver.h
 *
 *  Created on: Nov 8, 2024
 *      Author: panka
 */
#include <stdint.h>

#ifndef GPIO_DEVICEDRIVER_H_
#define GPIO_DEVICEDRIVER_H_

#define GPIO_BASEADDRESS 0X40020000
//base address for each port
#define GPIO_A GPIO_BASEADDRESS
#define GPIO_B 0X40020400
#define GPIO_C 0X40020800
#define GPIO_D 0X40020C00
#define GPIO_E 0X40021000
#define GPIO_H 0X4002C000

typedef struct GPIO_Configuration_Reg
{
	uint32_t MODE;
	uint32_t TYPE;
	uint32_t SPEED;
	uint32_t PUPDR;
}GPIO_Config_t;

typedef struct GPIO_Function_Reg
{
	uint32_t Res[4];
	uint32_t input;
	uint32_t output;
	uint32_t bit_set_reset;
	uint32_t config_lock;
	uint32_t alternate_function[2];
}GPIO_Reg_t;

void GPIO_init(uint32_t port);
void GPIO_config_pin(uint8_t pin, uint32_t port, uint8_t speed, uint8_t mode, uint8_t type, uint8_t pupd);
void GPIO_config_port(uint8_t speed, uint32_t port, uint8_t mode, uint8_t type, uint8_t pupd);
void GPIO_output_pin(uint8_t pin, uint32_t port, uint8_t data);
void GPIO_output_port(uint32_t port , uint32_t data);
uint8_t GPIO_input_pin(uint8_t pin, uint32_t port);
uint16_t GPIO_input_port(uint32_t port);
void GPIO_lock_config(uint32_t port);
void GPIO_alternate_func(uint32_t port, uint8_t pin, uint8_t mode);
/*
 * Parameters for GPIO_init
 */
enum{
	portA, portB, portC, portD, portE, portH = 7
};
/*
 *  Parameters for Configuring GPIO speed mode type pupd
 */
enum{
	Input,Output,Alternate,Analog, push_pull = 0, open_drain = 1,
	low_speed = 0, mid_speed  = 1, high_speed = 2, vhigh_speed = 3,
	No_pupd = 0, pull_up = 1, pull_down = 2
};
#endif /* GPIO_DEVICEDRIVER_H_ */
