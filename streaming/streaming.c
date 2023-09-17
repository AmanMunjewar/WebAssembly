#include<emscripten.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div_l(int a, int b);

EMSCRIPTEN_KEEPALIVE
int sumOf(int a){
    return div_l(mul(a,add(a,1)),2);
}