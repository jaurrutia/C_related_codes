/*
Jonathan Urrutia
2020/12/21

Scientific computing with CUDA course

pi stimation by montecarlo algorithm

we need to run it as follows :

gcc 3-Numerical-Int.c -lm
*/

#include <stdio.h>

int main(){
  float a, b;
  a = 1e13;
  b = 1e13;

  printf("%+e %+e\n", (a-b), a-b );
  printf("%+e %+e\n\n", (a-b)+1234567, a-(b-1234567) );

  a = 1e15;
  b = 1e15;

  printf("%+e %+e\n", (a-b), a-b );
  printf("%+e %+e\n\n", (a-b)+1234567, a-(b-1234567) );


}
