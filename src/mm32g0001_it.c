#include "mm32g0001_it.h"

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
    ;
}

void SVC_Handler(void)
{
}

void PendSV_Handler(void)
{
}