/*
Jonathan Urrutia
2020/12/21

Scientific computing with CUDA course

pi stimation by montecarlo algorithm

we need to run it as follows :

gcc 3-Numerical-Int.c -lm
*/

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float estimate_pi(long n);

int main(int argc, char* argv[]){
  srand(time(NULL));
  if(argc < 1){
    printf("Please input number of sample points\n");
    exit(-1);
  }
  long n = atoi(argv[1]);
  printf("Pi estimate: %7.6f\n", estimate_pi(n));
}



float estimate_pi(long n){
  float r, x, y;
  long pi = 0;
  for(int i = 0; i < n; i++){
    x = (float) rand() / RAND_MAX;
    y = (float) rand() / RAND_MAX;

    if((r = sqrt(x*x + y*y)) < 1)
      pi += 1;
  }
  return (float) 4.*pi / n;
}
