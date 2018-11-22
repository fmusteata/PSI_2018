/* 
 * File:   ADC.h
 * Author: uidn3175
 *
 * Created on July 27, 2017, 3:04 PM
 */

#ifndef ADC_H
#define	ADC_H

extern void ADC_vInit(void);
extern void ADC_vConversionCompleted(void);
extern T_U16 ADC_u16ReadAdcValue(T_U16 u16Channel);

#endif	/* ADC_H */

