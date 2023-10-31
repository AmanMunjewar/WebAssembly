#include<emscripten.h>

EMSCRIPTEN_KEEPALIVE
float add(float a, float b){
    return a+b;
}

EMSCRIPTEN_KEEPALIVE
float sub(float a, float b){
    return a-b;
}

EMSCRIPTEN_KEEPALIVE
float mul(float a, float b){
    return a*b;
}

EMSCRIPTEN_KEEPALIVE
float div_l(float a, float b){
    return (float) a/b;
}

EMSCRIPTEN_KEEPALIVE
int collatz(int n){
    if(n % 2 == 1){
        return 3  * n + 1;
    }
    else{
        return n / 2;
    }
}