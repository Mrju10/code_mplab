//File name: configOsc.h

#include "xc.h" // include processor files - each processor file is guarded.  
//#define FCY 7370000
#include <libpic30.h>

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CONFIG_FRCPLL_03_H
#define	CONFIG_FRCPLL_03_H



#define _XTAL_FREQ 12000000L
#define FRC 7370000L

#endif	/* XC_HEADER_TEMPLATE_H */