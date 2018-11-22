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
*  File name:           $Source: ADC.c $
*  Author:              $Author: Alexandra Muraru $
*  Module acronym:      ADC
*  Originator:          Alexandra Muraru
*  Specification:
*  Date:                $Date: 07.09.2017 $
*
*  Description:         Module that contains the initialization of ADC
*
*********************************************************************************
*
*  Changes:
*   $Log: ADC.c $
*
*********************************************************************************/


/* Include directive */
#include "global.h"

T_U16 u16AdcRs[2] = {0, 0}; 
T_U16 u16AdcCh2 = 0; 


/***********************************************************************************************************************
*  Function name    : ADC_vInit();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     :  void
*
***********************************************************************************************************************/
void ADC_vInit(void)
{
    /*light sensor */  
    AD1PCFGbits.PCFG1 = 0;        /*Analog input pin in Analog mode, digital port read will return as a ‘1’ 
                                   * without regard to the voltage on the pin, 
                                   * ADC samples pin voltage
                                   * ADC_DIAGLDR   = Senzor lumina*/
    AD1PCFGbits.PCFG2 = 0;        /*ADC_DIAGL     = Linie diagnoza*/    
    AD1CON1 = 0x0000;       // SAMP bit = 0 ends sampling ...
                            // and starts converting
    AD1CHS = 0;
    AD1CHSbits.CH0SA = 1;    //Channel 0 positive input is AN1(MUX A)
                             // Connect RB1/AN1 as CH0 input ..
                             // in this example RB1/AN1 is the input
                             
    AD1CHSbits.CH0SB = 2;   ////Channel 0 positive input is AN1(MUX B)
    AD1CSSL = 0;         /* CSSL<15:0>: ADC Input Pin Scan Selection bits
                            1 = Select ANx for input scan
                            0 = Skip ANx for input scan */
    AD1CON3 = 0x0002;       /* Manual Sample, Tad = internal 2 Tcy
                             AD1CON3bits.ADCS=2;  */
    AD1CON2 = 0;
    AD1CON2bits.SMPI = 1;       /*Interrupts at the completion of conversion for each 2nd sample/convert sequence*/
    AD1CON1bits.SSRC = 0x07;    /*Internal counter ends sampling and starts conversion (auto-convert)*/
    AD1CON1bits.ASAM = 1;       /*Sampling begins immediately after last conversion completes; SAMP bit is automatically set.*/
    AD1CON2bits.ALTS = 1;       /*Uses MUX A input multiplexer settings for first sample, then alternates between MUX B and
                                  MUX A input multiplexer settings for all subsequent samples*/
    AD1CON1SET = 0x8000;     // turn ADC ON  
}

/***********************************************************************************************************************
*  Function name    : ADC_vConversionCompleted();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     :  void
*
***********************************************************************************************************************/
void ADC_vConversionCompleted(void)
{
    u16AdcRs[0] = ADC1BUF0;
    u16AdcRs[1] = ADC1BUF1;
}

/***********************************************************************************************************************
*  Function name    : ADC_u16ReadAdcValue();
*
*  Description      : 
*
*  List of arguments: T_U16 u8Channel
*
*  Return value     :  T_U16 u16Result
*
***********************************************************************************************************************/
T_U16 ADC_u16ReadAdcValue(T_U16 u16Channel)
{
    T_U16 u16Result = 0;
    
    if(u16Channel < 2)
    {
      u16Result =  u16AdcRs[u16Channel];
    }  
    return u16Result;
}