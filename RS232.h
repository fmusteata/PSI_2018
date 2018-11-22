/* 
 * File:   RS232.h
 * Author: uidn3175
 *
 * Created on August 4, 2017, 2:05 PM
 */

#include "global.h"

#ifndef RS232_H
#define	RS232_H

#define RS232_BUFFER_SIZE 1024
#define UART_MODULE_ID 0
    
extern void RS232_vInit(void);
extern void RS232_vSendMessage(const char u8Message[],char lenght);
extern void RS232_vMainFunction();
extern void RS232_vReceiveMessage(void);
extern T_U8 RS232_u8GetValueRx(void);

#endif	/* RS232_H */





