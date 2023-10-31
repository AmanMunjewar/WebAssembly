#include<emscripten.h>
#include<stdlib.h>

int main(){ return 0; }

EMSCRIPTEN_KEEPALIVE
unsigned char* randString(int len){
    unsigned char* str = malloc(len+1);

    srand(time(NULL);

    for (i=0; i<len; i++>){
        //generate a printable character
        str[i] = rand() % (127 - 33) +33;
    }
    str[len] = 0;
    return str;
}