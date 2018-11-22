/* 
 * File:   global.h
 * Author: uidn3175
 *
 * Created on July 26, 2017, 10:28 AM
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

/* uC header file */

#include <xc.h>
#include <sys/attribs.h>
#include <p32xxxx.h>

/* Type definition */
typedef unsigned char T_U8;
typedef signed char   T_S8;
typedef unsigned int  T_U32;
typedef unsigned short  int  T_U16;
typedef signed int    T_S16;
typedef unsigned char T_BOOL;

typedef int           T_16;
typedef char          T_8; 

//#define TRUE (1)
//#define FALSE (!TRUE)

#define SYS_FREQ (80000000L)

#define	GetPeripheralClock()		(SYS_FREQ/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()		(SYS_FREQ)
#define UART_BD_RATE                 9600


#endif	/* GLOBAL_H */