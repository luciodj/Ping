/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using MPLAB® Code Configurator

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.10.3
        Device            :  PIC16F1709
        Driver Version    :  1.02
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

#include "interrupt_manager.h"
#include "mcc.h"

#define T1CLK   _XTAL_FREQ / 4
#define T1PERIOD        (unsigned)(T1CLK * 0.050)                  // period
#define HOLDOFF         (unsigned)(T1CLK * 0.000750)               // hold off time

void interrupt INTERRUPT_InterruptManager (void)
{
    unsigned capt;
    if( PIR1bits.CCP1IF)                // capture function
    {
        capt = *(unsigned *)&CCPR1L;        // read the captured value
        capt -= HOLDOFF;                    // subtract hold off time
        capt >>= 3;                         // div 8 -> 2cm-300cm [0-255]

        if ( capt > 20)
            LATC = 0;
        else if ( capt > 16)                    // > 2.6m
            LATC = 0xB;
        else if ( capt > 12)               // 1.3m - 2.6m
            LATC = 8;
        else if ( capt > 8)                // 0.65 - 1.3m
            LATC = 2;
        else if ( capt > 4)                // 0.32 - 0.65m
            LATC = 1;

        PIR1bits.CCP1IF = 0;                // clear flag
    }

    if( PIR2bits.CCP2IF)               // compare function
    {
        LATCbits.LATC2 = 1;
        TRISCbits.TRISC2 = 0;               // output
        LATCbits.LATC2 = 0;                 // for 1 Tcy = 8us @500KHz
        TRISCbits.TRISC2 = 1;               // restore input
        NOP();

    PIR1bits.CCP1IF = 0;                    // ignore first falling edge detected
    PIR2bits.CCP2IF = 0;                    // clear flag
    }
}
/**
 End of File
*/