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
*  File name:           $Source: SCHED.c $
*  Author:              $Author: Alexandra Muraru $
*  Module acronym:      SCHED
*  Originator:          Alexandra Muraru
*  Specification:
*  Date:                $Date: 07.09.2017 $
*
*  Description:         Module that calls functions at some point
*
*********************************************************************************
*
*  Changes:
*   $Log: SCHED.c $
*
*********************************************************************************/

#include "global.h"




T_U16 u16counter10ms = 3;
T_U16 u16counter100ms = 0;


/***********************************************************************************************************************
*  Function name    : Sched_vMain();
*
*  Description      : 
*
*  List of arguments: none
*
*  Return value     :  void
*
***********************************************************************************************************************/
void Sched_vMain(void)   // se apeleaza la 1 ms
{
    u16counter10ms ++;
    u16counter100ms ++;
    
    //RTE_vTask1ms();         // se apeleaza la 1 ms
    
    if(u16counter10ms >= 10)
    {
        u16counter10ms = 0;
        //RTE_vTask10ms();    // se apeleaza la 10 ms
    }
    
    if(u16counter100ms >= 100)
    {
        u16counter100ms = 0;
        //RTE_vTask100ms();       // se apeleaza la 100 ms
    }
}