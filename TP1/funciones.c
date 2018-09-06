#include "funciones.h"

float add(float a, float b){
    return a+b;
}

float subtract(float a, float b){
    return a-b;
}

float multiplicate(float a, float b){
    return a*b;
}

int divide(float a, float b, float *pResult){
    int val=1;

    if(b!=0)
        val=0;

    *pResult=a/b;
    return val;
}

int factorial(float a, long *pFact){
    int i, val=1;
    *pFact=1;

    if(a>=0)
        val=0;

    for(i = (int)a;i > 0; i--)
        *pFact*=i;

    return val;
}

