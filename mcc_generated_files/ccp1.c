/**
  CCP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp1.c

  @Summary
    This is the generated driver implementation file for the CCP1 driver using MPLAB® Code Configurator

  @Description
    This source file provides APIs for CCP1.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10.3
        Device            :  PIC16F1709
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X 2.26
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "ccp1.h"

/**
  Section: Capture Module APIs
*/

void CCP1_Initialize(void)
{
    // Set the CCP1 to the options selected in the User Interface

    // CCP1M capture_fallingedge; DC1B LSBs; 
    CCP1CON = 0x04;    

    // CCPR1L 0x0; 
    CCPR1L = 0x00;    

    // CCPR1H 0x0; 
    CCPR1H = 0x00;    

    // Clear the CCP1 interrupt flag
    PIR1bits.CCP1IF = 0;

    // Enable the CCP1 interrupt
    PIE1bits.CCP1IE = 1;
}

void CCP1_CaptureISR(void)
{
    CCP_PERIOD_REG_T module;

    // Clear the CCP1 interrupt flag
    PIR1bits.CCP1IF = 0;
    
    // Copy captured value.
    module.ccpr1l = CCPR1L;
    module.ccpr1h = CCPR1H;
    
    // Return 16bit captured value
    CCP1_CallBack(module.ccpr1_16Bit);
}

void CCP1_CallBack(uint16_t capturedValue)
{
    // Add your code here
}
/**
 End of File
*/