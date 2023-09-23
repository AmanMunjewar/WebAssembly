#include<stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
      double time_spent;

      start = clock();
      for (int i=0; i<2147483647; i++){}
      end = clock();

      time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;

      printf("Time spent in my_function(): %f seconds\n", time_spent);
    return 0;
}