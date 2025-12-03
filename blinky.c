//#############################################################################
//
// 
// $Copyright:
// Copyright (C) 2013-2025 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

#include "driverlib.h"
#define L 10
void Funktion1(void);
#include "device.h"
#define T 500000
void Funktion2(uint32_t pin, uint32_t z, uint16_t count);
void main(void)
{

    for(;;)
    {
        Funktion1();
        Funktion2(DEVICE_GPIO_PIN_LED1, T, 5);
        DEVICE_DELAY_US(3 * T); 
    }
}
void Funktion1(void){
    Device_init();
    Device_initGPIO();
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1,GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1,GPIO_DIR_MODE_OUT);
    Interrupt_initModule();
    Interrupt_initVectorTable();
    EINT;ERTM;
}
void Funktion2(uint32_t pin, uint32_t z, uint16_t count)
{
    for(uint16_t i = 0; i < count; i++)
    {
        GPIO_writePin(pin, 0);
        DEVICE_DELAY_US(z);

        GPIO_writePin(pin, 1);
        DEVICE_DELAY_US(z);
    }
}