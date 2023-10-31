#include <emscripten.h>
#include <stdio.h>
#include <time.h>

EMSCRIPTEN_KEEPALIVE
void write(){
    FILE *fp = fopen("test.txt", "w");
      if (fp == NULL) {
        printf("Error opening file.\n");
      }

        for (int i = 0; i < 1000; ++i) {
            fprintf(fp, "%d\n",i);
        }

      // Close the file.
      fclose(fp);
}

EMSCRIPTEN_KEEPALIVE
void count(){
    clock_t start, end;
    double time_spent;
    start = clock();
    write();
    end = clock();

    time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time spent C: %f seconds\n", time_spent);
}

int main(){
    return 0;
}