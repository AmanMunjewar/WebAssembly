#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
int accumulate(int *arr, int n){
    int sum = 0;
    while(n){
        sum += arr[--n];
    }
    return sum;
}

EMSCRIPTEN_KEEPALIVE
const char* getString(){
    return "Hello WebAssembly!";
}

EMSCRIPTEN_KEEPALIVE
void *wasmmalloc(size_t n){
    return malloc(n);
}

EMSCRIPTEN_KEEPALIVE
void wasmfree(void *ptr){
    free(ptr);
}

int main(){
    return 0;
}