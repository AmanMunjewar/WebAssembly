#include<emscripten.h>

EMSCRIPTEN_KEEPALIVE
int addNum(int a, int b){
    return a+b;
}

EMSCRIPTEN_KEEPALIVE
int subNum(int a, int b){
    return a-b;
}

EMSCRIPTEN_KEEPALIVE
int mulNum(int a, int b){
    return a*b;
}

EMSCRIPTEN_KEEPALIVE
int divNum(int a, int b){
    return a/b;
}

EMSCRIPTEN_KEEPALIVE
int main(){
    return 0;
}