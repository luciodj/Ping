/**
  CCP2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp2.c

  @Summary
    This is the generated driver implementation file for the CCP2 driver using MPLAB® Code Configurator

  @Description
    This header file provides implementations for driver APIs for CCP2.
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
#include "ccp2.h"

/**
  Section: COMPARE Module APIs
*/

void CCP2_Initialize(void)
{
    // Set the CCP2 to the options selected in the User Interface
    
    // CCP2M compare_softint; DC2B LSBs; 
    CCP2CON = 0x0A;
    
    // CCPR2L 0x0; 
    CCPR2L = 0x00;
    
    // CCPR2H 0x0; 
    CCPR2H = 0x00;

    // Enable the CCP2 interrupt
    PIE2bits.CCP2IE = 1;
}

void CCP2_SetCompareCount(uint16_t compareCount)
{
    CCP_PERIOD_REG_T module;
    
    // Write the 16-bit compare value
    module.ccpr2_16Bit = compareCount;
    
    CCPR2L = module.ccpr2l;
    CCPR2H = module.ccpr2h;
}

void CCP2_CompareISR(void)
{
    // Clear the CCP2 interrupt flag
    PIR2bits.CCP2IF = 0;
}
/**
 End of File
*/