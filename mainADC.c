#include <stdio.h>
#include <stdlib.h>
#include "configBIT00.h"
#include "osc00.h"

//#include "configOsc.h"
//DEFINIR EL VALOR DE FCY
#define FCY 2000000
#include "p33Fxxxx.h"
//#elif defined(__PIC24H__)
//#include "p24Hxxxx.h"
//Declarar una función llamada adc_init()


int main()
{
    OSCCONbits.NOSC = 0b11;
    //CONFIGURAR LOS PLL DEL DSPIC33FJ64GP802
    //M=4, N1=2, N2=2
    CLKDIVbits.DOZEN=0;
    PLLFBDbits.PLLDIV=0x04;//M=4
    //N1=2, N2=2
    int adcval;
    CLKDIVbits.PLLPOST=0x00;
    CLKDIVbits.PLLPRE=0x00;
    adc_init();
    while(1)
    {
    // DAR INICIO AL MUESTREO
        __delay32(10);
        LATBbits.LATB13 = 0;
        AD1CON1bits.SAMP=1;
        __delay32(100);
        AD1CON1bits.SAMP=0;
        AD1CON1bits.DONE=0;
        //AUTOMATICAMENTE SE INICIA LA CONVERSION
        while(!AD1CON1bits.DONE);
        //CONVERCION HECHA
        adcval=ADC1BUF0;
        LATB=adcval;
        LATBbits.LATB13 = 1;
    }
    //return ();
    //return (EXIT_SUCCESS);
}
