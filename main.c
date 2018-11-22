/*
 * File:   main.c
 * Author: uidn3175
 *
 * Created on July 25, 2017, 1:00 PM
 */

/*
 * Proiectarea sistemelor incorporate mediu de proiectare
 * Copyright (C) 2013 Constantin Bogza
 * Continental AR - Iasi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


// PIC32MX440F256H Configuration Bit Settings

#include <p32xxxx.h>

// DEVCFG3
// USERID = No Setting

// DEVCFG2
/* Extrenal oscilator  8 Mhz*/
/* (8 Mhz / DIV_2 ) * MUL_20 => Sys_Clk = 80Mhz */
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_1         // USB PLL Input Divider (1x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)

// DEVCFG1
/* Sys_Clk / DIV_8 => Pb_Clk = 10MHz*/
#pragma config FNOSC = PRIPLL           // Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = XT             // Primary Oscillator Configuration (XT osc mode)
#pragma config OSCIOFNC = ON            // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FPBDIV = DIV_8           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1              // Watchdog Timer Postscaler (1:1)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

//#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
//#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1
            // Other options are don't care

/* Include directive */
#include "global.h"
#include "PCS.h"
#include "TMR.h"
#include "INT.h"
#include "ADC.h"
#include "RS232.h"

/***********************************************************************************************************************
*  Function name    : main();
*
*  Description      : 
*
*  List of arguments: int argc, char** argv
*
*  Return value     : 
*
***********************************************************************************************************************/
int main(int argc, char** argv) 
{
    const char u8StartUpMessage[] = "Sistem inteligent lumini masina v1.0";
    
    /* Initialization of ports */
    PCS_vInit();
    ADC_vInit();
    TMR_vInitTimer();    
    INT_vInit();
    RS232_vInit();
    
    RS232_vSendMessage(u8StartUpMessage,36);
 
    
    while(1) 
    {
       RS232_vMainFunction();
    }
    
    return 0;
}