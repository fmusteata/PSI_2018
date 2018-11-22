/* 
 * File:   pcs.h
 * Author: uidn3175
 *
 * Created on July 25, 2017, 2:48 PM
 */

#ifndef PCS_H
#define	PCS_H

extern void PCS_vInit(void);
extern void PCS_vSetOutputPortD(T_U16 u16BitPosition, T_U8 u8Value);
extern void PCS_vSetOutputPortE(T_U16 u16BitPosition, T_U8 u8Value);
extern void PCS_vSetOutputPortB(T_U16 u16BitPosition, T_U8 u8Value);
extern void PCS_vSetOutputPortG(T_U16 u16BitPosition, T_U8 u8Value);
extern T_16 PCS_vGetInputPortC(T_U8 u8BitNumber);


#endif	/* PCS_H */