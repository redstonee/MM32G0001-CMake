/***********************************************************************************************************************
    @file     hal_misc.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE NVIC
              FIRMWARE LIBRARY.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HAL_MISC_H
#define __HAL_MISC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup NVIC_HAL
  * @brief NVIC HAL modules
  * @{
  */

/** @defgroup NVIC_Exported_Types
  * @{
  */

/**
  * @brief  NVIC Init Structure definition
  */
typedef struct {
    uint8_t                                  NVIC_IRQChannel;
    uint8_t                                  NVIC_IRQChannelPriority;
    FunctionalState                     NVIC_IRQChannelCmd;
} NVIC_InitTypeDef;

/**
  * @brief  NVIC New Init Structure definition
  */
typedef struct {
    uint8_t                                  NVIC_IRQChannel;
    uint8_t                                  NVIC_IRQChannelPreemptionPriority;      /*!< Cortex-M0 not used */
    uint8_t                                  NVIC_IRQChannelSubPriority;
    FunctionalState                     NVIC_IRQChannelCmd;
} exNVIC_Init_TypeDef;

/**
  * @}
  */

/** @defgroup NVIC_Exported_Constants
  * @{
  */
#define NVIC_VectTab_RAM                (0x20000000U)
#define NVIC_VectTab_FLASH              (0x08000000U)

#define NVIC_LP_SEVONPEND               (0x10U)
#define NVIC_LP_SLEEPDEEP               (0x04U)
#define NVIC_LP_SLEEPONEXIT             (0x02U)

#define NVIC_PriorityGroup_0            (0x0700U)                               /*!< 0 bits for pre-emption priority 4 bits for subpriority */
#define NVIC_PriorityGroup_1            (0x0600U)                               /*!< 1 bits for pre-emption priority 3 bits for subpriority */
#define NVIC_PriorityGroup_2            (0x0500U)                               /*!< 2 bits for pre-emption priority 2 bits for subpriority */
#define NVIC_PriorityGroup_3            (0x0400U)                               /*!< 3 bits for pre-emption priority 1 bits for subpriority */
#define NVIC_PriorityGroup_4            (0x0300U)                               /*!< 4 bits for pre-emption priority 0 bits for subpriority */

#define AIRCR_VECTKEY_MASK              (0x05FA0000U)


#define SysTick_CLKSource_HCLK_Div4     (0xFFFFFFFBU)

#define SysTick_CLKSource_EXTCLK        (0xFFFFFFFBU)
#define SysTick_CLKSource_HCLK          (0x00000004U)
/**
  * @}
  */

/** @defgroup NVIC_Exported_Variables
  * @{
  */

#ifdef _HAL_MISC_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL



/**
  * @}
  */

/** @defgroup NVIC_Exported_Functions
  * @{
  */


void NVIC_SystemLPConfig(uint8_t low_power_mode, FunctionalState state);
void NVIC_Init(NVIC_InitTypeDef* init_struct);

void SysTick_CLKSourceConfig(uint32_t systick_clk_source);

void exNVIC_Init(exNVIC_Init_TypeDef* init_struct);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

/** --------------------------------------------------------------------------*/
#endif /* __HAL_NVIC_H -------------------------------------------------------*/
/** --------------------------------------------------------------------------*/
