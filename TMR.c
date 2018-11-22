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
*  File name:           $Source: TMR.c $
*  Author:              $Author: Alexandra Muraru $
*  Module acronym:      TMR
*  Originator:          Alexandra Muraru
*  Specification:
*  Date:                $Date: 07.09.2017 $
*
*  Description:         Module that contains the dsPIC EP code image
*
*********************************************************************************
*
*  Changes:
*   $Log: TMR.c $
*
*********************************************************************************/

#include "global.h"
#include "TMR.h"


/***********************************************************************************************************************
*  Function name    : TMR_vInitTimer();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     : void
*
***********************************************************************************************************************/
void TMR_vInitTimer(void)
{    
    T1CON = 0x0;            // Stop the Timer and Reset Control register                
    TMR1 = 0x0;             // Clear timer register
    
    T1CONbits.TCS=0;        //Internal peripheral clock
    T1CONbits.TGATE=0;      //Gated time accumulation is disabled
    T1CONbits.TCKPS=0;      //1:1 prescale value
    PR1 = 10000;            // Set the PR1 register to 10000 because the freq in is 10Mhz
    T1CONbits.ON=1;         //Timer is enabled 
}