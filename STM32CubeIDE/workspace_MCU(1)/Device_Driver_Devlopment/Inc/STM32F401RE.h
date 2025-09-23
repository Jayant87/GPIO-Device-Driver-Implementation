/*
 * STM32F401RE.h
 *
 *  Created on: Nov 8, 2024
 *      Author: panka
 */
#include <stdint.h>

#ifndef STM32F401RE_H_
#define STM32F401RE_H_

#define RCC 0x40023800U

typedef struct RCC_register
{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RST;
	uint32_t AHB2RSTR;
	uint32_t RESERVED[2];
	uint32_t APB1RST;
	uint32_t APB2RST;
	uint32_t RES1[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t RES3[2];
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RES4[2];
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t RES5[2];
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RES6[2];
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RES7[2];
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t RES8;
	uint32_t DCKCFGR;
}RCC_t;

RCC_t *Rcc_reg = (RCC_t*)RCC;

#endif /* STM32F401RE_H_ */
