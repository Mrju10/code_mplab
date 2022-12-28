/*
 * File:   configADC.c
 * Author: pc
 *
 * Created on 27 de octubre de 2022, 01:27 PM
 */

#include "xc.h"

void adc_init(void);
//Definir la función adc_init()
void adc_init(void)
{//PARA LA CONFIGURACION DE ADC DE DSPIC
  //RA0 COMO PIN ANALÓGICO
    AD1PCFGL=0XFFFE;//ANALOGICO
    TRISB=0x0000;
    //12 bits
    AD1CON1bits.AD12B=0b11;
    // Representación de números enteros positivos
    AD1CON1bits.FORM=0b00;
    // El inicio de muestreo sea manual
    AD1CON1bits.ASAM=0;
    // El inicio de la conversión sea manual
    AD1CON1bits.SSRC=0b000;
    // Elegir canal
    AD1CON2bits.CHPS=0b00;
    // VREF+ = AVDD Y VREF- = AVSS
    AD1CON2bits.VCFG=0b000;
    //
    AD1CON3bits.ADRC=0;
    AD1CON3bits.ADCS=2;
    AD1CHS0bits.CH0NA=0;// VREF- ES EL PIN NEGATIVO
    AD1CHS0bits.CH0SA=0;// VREF+ ES EL PIN POSITIVO
    // Encender el ADC
    AD1CON1bits.ADON=1;
    
}





