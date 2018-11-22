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
*  File name:           $Source: RS232.c $
*  Author:              $Author: Alexandra Muraru $
*  Module acronym:      RS232
*  Originator:          Alexandra Muraru
*  Specification:
*  Date:                $Date: 07.09.2017 $
*
*  Description:         Module that contains the UART configuration
*
*********************************************************************************
*
*  Changes:
*   $Log: RS232.c $
*
*********************************************************************************/

#include "global.h"
#include "rs232.h"
#include "uart.h"


long unsigned u16Counter;
long unsigned u16Index;
T_U8 u8ValueRx = 0xFF;
char message_array_Buffer[RS232_BUFFER_SIZE];


/***********************************************************************************************************************
*  Function name    : RS232_u8GetValueRx();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     : T_U8 u8ValueRx
*
***********************************************************************************************************************/
T_U8 RS232_u8GetValueRx(void)
{
    return u8ValueRx;
}


/***********************************************************************************************************************
*  Function name    : RS232_vInit();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     : void
*
***********************************************************************************************************************/
void RS232_vInit(void)
{
    UARTConfigure(UART_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART_MODULE_ID, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART_MODULE_ID, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART_MODULE_ID, GetPeripheralClock(), 9600);
    UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}


/***********************************************************************************************************************
*  Function name    : RS232_vSendMessage();
*
*  Description      : 
*
*  List of arguments: const char u8Message[],char lenght
*
*  Return value     : void
*
***********************************************************************************************************************/
void RS232_vSendMessage(const char u8Message[],char lenght)
{
    int u16Cnt = 0;
    while(u16Cnt<lenght)
    {
        message_array_Buffer[(u16Index+u16Cnt)%RS232_BUFFER_SIZE] = u8Message[u16Cnt];
        u16Cnt++;
    }
    message_array_Buffer[(u16Index+u16Cnt)%RS232_BUFFER_SIZE] = '\n';
    message_array_Buffer[(u16Index+u16Cnt+1)%RS232_BUFFER_SIZE] = '\r';
    u16Index=(u16Index+lenght+2)%RS232_BUFFER_SIZE;

}


/***********************************************************************************************************************
*  Function name    : RS232_vMainFunction();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     : void
*
***********************************************************************************************************************/
void RS232_vMainFunction(void)
{
   if(u16Counter != u16Index)
   {
       if(UARTTransmitterIsReady(UART_MODULE_ID))
       {
            UARTSendDataByte(UART_MODULE_ID, message_array_Buffer[u16Counter]);
            u16Counter=(u16Counter+1)%RS232_BUFFER_SIZE;
       }
   }
}