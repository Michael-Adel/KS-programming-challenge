#ifndef PRINTAPI_H
#define PRINTAPI_H
#if PLATFORM == 0 //for Platform A
#include "printA.h"
#define PRINT printA
#endif // PLATFORM == 0 //for Platform A
//#elif PLATFORM == 1
//#include "printB.h"
//#define PRINT printB
#endif

