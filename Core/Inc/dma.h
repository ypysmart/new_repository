/**
  ******************************************************************************
  * @file    dma.h
  * @brief   This file contains all the function prototypes for
  *          the dma.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DMA_H__
#define __DMA_H__

/* Includes ------------------------------------------------------------------*/


/* DMA memory to memory transfer handles -------------------------------------*/

/* USER CODE BEGIN Includes */
//////////////////////////////////////////////////////////////
#include "usart.h"
#include "main.h"
#define USART1_RX_LEN_MAX 18
#define RC_CtrlData_Initialize {1024,1024,1024,1024,2,2}

typedef  struct {     

	struct{         
				uint16_t ch0;         
				uint16_t ch1;         
				uint16_t ch2;         
				uint16_t ch3;         
				uint8_t  s1;         
				uint8_t  s2;     
				}rc;  	 
}RC_Ctl_t;

typedef struct UART_RX_BUFFER
{
	uint8_t* Buffer[2];
	uint8_t Buffer_Num;
	uint16_t Length_Max;
}UART_RX_BUFFER;
//---------------------------------//

//-------------????------------//
void Uart1_All_Init(void);						//????????? 
void uart_sendData_DMA(UART_HandleTypeDef *huart, uint8_t *Data, uint8_t len);			//??DMA???? 
void Uart_DMA_Process(UART_HandleTypeDef *huart,DMA_HandleTypeDef* hdma_usart_rx, UART_RX_BUFFER* Uart_Rx,void(*DataProcessFunc)(uint8_t *pData));	//??DMA?????? 


void Remote_Init(void);
void Usart_Receive_IDLE(UART_HandleTypeDef *_huart);
void RemoteDataProcess(uint8_t *pData);

//---------------------------------//
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_DMA_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#endif /* __DMA_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
