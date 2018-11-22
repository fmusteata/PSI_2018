/********************************************************************************
*
* Proiectarea sistemelor incorporate mediu de proiectare
* Copyright (C) 2017 Continental AR 
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
*
*  File name:           $Source: INT.c $
*  Author:              $Author: Alexandra Muraru $
*  Module acronym:      INT
*  Originator:          Alexandra Muraru
*  Specification:
*  Date:                $Date: 07.09.2017 $
*
*  Description:         Module that contains the configuration of interrupt
*
*********************************************************************************
*
*  Changes:
*   $Log: INT.c $
*
*********************************************************************************/

#include "global.h"
#include "SCHED.h"
#include "ADC.h"

/***********************************************************************************************************************
*  Function name    : ADC_vInit();
*
*  Description      : Functia realizeaza initializarea driverului de INT. 
*                     2 întreruperi vor fi procesate: ADC si SCHED.
*
*  List of arguments: none
*
*  Return value     :  void
*
***********************************************************************************************************************/
void INT_vInit(void) 
{
    /* Configure Timer 1 interrupt */  
    
    IPC1bits.T1IP = 3;              /* Set Timer 1 inetrrupt priority level */    
    IPC1bits.T1IS = 3;              /* Set Timer 1 inetrrupt sub-priority level */    
    IFS0bits.T1IF = 0;              /* Clear Timer 1 interrupt flag */    
    IEC0bits.T1IE = 1;              /* Enable Timer 1 interrupt source */

    /* Configure ADC interrupt */ 
    IPC6bits.AD1IP = 4; // Set Priority to 4 
    IPC6bits.AD1IS = 3; // Set Sub Priority to 4   
    IFS1bits.AD1IF = 0; // Ensure the interrupt flag is clear
    IEC1bits.AD1IE = 1;  // Enable ADC interrupts
    
    INTCONSET = 0x1000;             /* Set MVEC bit. Enable individual function handler for each interrupt */        
    asm("ei");                      /* Enable all interrupt sources */ 
}

/***********************************************************************************************************************
*  Function name    : __ISR(_TIMER_1_VECTOR, IPL3) Timer1Handler();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     :  void
*
***********************************************************************************************************************/
void __ISR(_TIMER_1_VECTOR, IPL3) Timer1Handler(void) 
{
    
   Sched_vMain();
   IFS0bits.T1IF = 0;     /* Clear interrupt flag for Timer 1 interrupt */  
}

/***********************************************************************************************************************
*  Function name    : __ISR(_ADC_VECTOR, IPL4) AdcHandler();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     :  void
*
***********************************************************************************************************************/
void __ISR(_ADC_VECTOR, IPL4) AdcHandler(void) 
{    
    ADC_vConversionCompleted(); 
    IFS1bits.AD1IF = 0;    /* Clear interrupt flag for ADC interrupt */     
}
