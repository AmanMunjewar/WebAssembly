#include<stdio.h>
#include<emscripten.h>

EMSCRIPTEN_KEEPALIVE
int numAdd(int a, int b){
    return a+b;
}

EMSCRIPTEN_KEEPALIVE
int numSub(int a, int b){
    return a-b;
}

EMSCRIPTEN_KEEPALIVE
int main(){
    return 0;
}