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
*  File name:           $Source: PCS.c $
*  Author:              $Author: Alexandra Muraru $
*  Module acronym:      PCS
*  Originator:          Alexandra Muraru
*  Specification:
*  Date:                $Date: 07.09.2017 $
*
*  Description:         Module that contains the initialization of ports
*
*********************************************************************************
*
*  Changes:
*   $Log: PCS.c $
*
*********************************************************************************/


/* Include directive */
#include "global.h"

#define PCS_PIN_ON 1
#define PCS_PIN_OFF 0

/***********************************************************************************************************************
*  Function name    : PCS_vInit();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     : void
*
***********************************************************************************************************************/
void PCS_vInit(void)
{
    TRISD=0x00;;
    ODCD=0x00;
    
    TRISE=0x00;
    ODCE=0x00;
    
    TRISC=0xFF; 
    ODCC=0xFF;
    
    TRISBbits.TRISB3 = 0; 
    ODCBbits.ODCB3 = 0;   
    TRISBbits.TRISB4 = 0; 
    ODCBbits.ODCB4 = 0;
    
    TRISBbits.TRISB2 = 1; 
    ODCBbits.ODCB2 = 0;   
    TRISBbits.TRISB1 = 1; 
    ODCBbits.ODCB1 = 0;
    
    TRISBbits.TRISB14 = 0; 
    ODCBbits.ODCB14 = 0;
    
    TRISDbits.TRISD6 = 0; 
    ODCDbits.ODCD6 = 0;
    
    
    /* Configure UART pins */
    TRISDbits.TRISD2= 1;    //RD2 input pin-UxRX
    ODCDbits.ODCD2=0;       /*  1 = Port pin open-drain output enabled
                                0 = Port pin open-drain output disabled
                                If a port pin is configured as an input, ODCx bits have no effect.*/
    TRISDbits.TRISD3= 0;    //RD3 output pin-UxTX
    ODCDbits.ODCD3= 0;      /*  1 = Port pin open-drain output enabled
                                0 = Port pin open-drain output disabled
                                If a port pin is configured as an input, ODCx bits have no effect. */
    LATD = 0;
    LATB = 0;
    LATE = 0;
    LATC = 0;
}

/***********************************************************************************************************************
*  Function name    : PCS_vSetOutputPortD();
*
*  Description      : 
*
*  List of arguments: T_U16 u16BitPosition, T_U8 u8Value
*
*  Return value     :  void
*
***********************************************************************************************************************/
void PCS_vSetOutputPortD(T_U16 u16BitPosition, T_U8 u8Value)
{
    if (u8Value > 1)
    {
        u8Value = 1;
    }
    else
    {
        /* Do nothing */
    }
    if(u8Value==1)
    {
        LATDSET = u16BitPosition ;
    }
    else if(u8Value==0)
    {
        LATDCLR =  u16BitPosition ;
    }
}

/***********************************************************************************************************************
*  Function name    : PCS_vSetOutputPortE();
*
*  Description      : 
*
*  List of arguments: T_U16 u16BitPosition, T_U8 u8Value
*
*  Return value     : void
*
***********************************************************************************************************************/
void PCS_vSetOutputPortE(T_U16 u16BitPosition, T_U8 u8Value)
{
    if (u8Value > 1)
    {
        u8Value = 1;
    }
    else
    {
        /* Do nothing */
    }
 
    if(u8Value==1)
    {
        LATESET= u16BitPosition;
    }
    else if(u8Value==0)
    {
        LATECLR=u16BitPosition;
    }
}

/***********************************************************************************************************************
*  Function name    : PCS_vSetOutputPortB();
*
*  Description      : 
*
*  List of arguments: T_U16 u16BitPosition, T_U8 u8Value
*
*  Return value     :  void
*
***********************************************************************************************************************/
void PCS_vSetOutputPortB(T_U16 u16BitPosition, T_U8 u8Value)
{
    if(u8Value>1)
    {
        u8Value=1;
    }
    else
    {
        //Do something
    }
    
    if(u8Value==1)
    {
        LATBSET= u16BitPosition;
    }
    else if(u8Value==0)
    {
        LATBCLR= u16BitPosition;
    }
} 

/***********************************************************************************************************************
*  Function name    : PCS_vSetOutputPortG();
*
*  Description      : 
*
*  List of arguments: T_U16 u16BitPosition, T_U8 u8Value
*
*  Return value     :  void
*
***********************************************************************************************************************/
void PCS_vSetOutputPortG(T_U16 u16BitPosition, T_U8 u8Value)
{
    if(u8Value>1)
    {
        u8Value=1;
    }
    else
    {
        //Do something
    }
    
    if(u8Value==1)
    {
        LATGSET= u16BitPosition;
    }
    else if(u8Value==0)
    {
        LATGCLR=u16BitPosition;
    }
}

/***********************************************************************************************************************
*  Function name    : PCS_vGetInputPortC();
*
*  Description      : 
*
*  List of arguments: T_U8 u8BitNumber
*
*  Return value     : void
*
***********************************************************************************************************************/
T_16 PCS_vGetInputPortC(T_U8 u8BitNumber)
{
    
    switch(u8BitNumber)
    {
        case 15:
        {
            return PORTCbits.RC15;
        }
        break;
        case 14:
        {
            return PORTCbits.RC14;
        }    
        break;
        case 13:
        {
            return PORTCbits.RC13;
        }
        break;
        case 12:
        {
            return PORTCbits.RC12;
        }
        break;
            default:
        {
            /*do nothing*/
        }
    }
}