/****************************************Copyright (c)****************************************************
**                                 TDTC Tech Dev
**                                     HRB
**--------------File Info---------------------------------------------------------------------------------
** File name:           main.c
** Last modified Date:  
** Last Version:        
** Descriptions:        
**
**--------------------------------------------------------------------------------------------------------
** Created by:          TDTC
** Created date:        2015-07-09
** Version:             V0.01
** Descriptions:        UART Send
**
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "LPC17xx.h"
#include "uart.h"
#include <string.h>
                                                                /* ------------------------ BEEP -------------------------- */
#define    BEEP         1UL << 7                                /* P0.7                                                     */
#define    BEEP_INIT()  LPC_GPIO0->FIODIR |= BEEP               /* beep init                                                */
#define    BEEP_OFF()   LPC_GPIO0->FIOSET |= BEEP               /* beep close                                               */
#define    BEEP_ON()    LPC_GPIO0->FIOCLR |= BEEP               /* beep open                                                */


#define    LED          1UL << 8                                 /* P2.8       */
#define    LED_INIT()   LPC_GPIO2->FIODIR |= LED                 /* LED INIT   */
#define    LED_OFF()    LPC_GPIO2->FIOSET |= LED                 /* LED OFF    */
#define    LED_ON()     LPC_GPIO2->FIOCLR |= LED                 /* LED ON     */

const uint32_t led_mask[] = { 1UL<<0, 1UL<<1, 1UL<<2, 1UL<<3, 1UL<<4, 1UL<<5, 1UL<<6, 1UL<<7};

/*********************************************************************************************************
** Function name:       Delay
** Descriptions:        software delay
** input parameters:    ulTime
** output parameters:   no
** Returned value:      no
*********************************************************************************************************/
void Delay (uint32_t Time)
{
    uint32_t i;
    
    i = 0;
    while (Time--) {
        for (i = 0; i < 5000; i++);
    }
}

void ledOff(uint8_t led)
{   
    LPC_GPIO2->FIOSET |= led_mask[led];
}

void ledOn(uint8_t led)
{
    LPC_GPIO2->FIOCLR |= led_mask[led];
}


int main(void)
{
    uint8_t *pBuffer;
    
    pBuffer = "Hello World!\n";
    
    SystemInit();
    UARTInit(0, 9600);
    
    // BEEP
    BEEP_INIT();
    BEEP_OFF();

    // LED
    LED_INIT();
    LED_OFF();
    
    while (1) 
    {
        BEEP_ON();
        LED_ON();
        
        UARTSend(0, pBuffer, strlen(pBuffer));
        
        Delay(1500);
        LED_OFF();
        Delay(10000);

        BEEP_OFF();
        Delay(6000);
    }
    
}
