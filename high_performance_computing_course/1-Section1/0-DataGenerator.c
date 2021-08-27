/*
Jonathan Urrutia
2020/12/21

Scientific computing with CUDA course

Data generator
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of points in the original datasheet
#define BASE_RES 10

// The order of the polynomial we are interpolating
#define ORDER 5



int main(){
  // generate our input data (as imple sine curve)
  float xs[BASE_RES], ys[BASE_RES];

  for(int i = 0; i < BASE_RES; i++){
    xs[i] = 4. * M_PI*((float) i)/BASE_RES;
    ys[i] = sin(xs[i]);
  }

  result res = interpolate(xs, ys, BASE_RES, ORDER+1); //Interpolate to 10x higher resolution

  for(int i = 0; i < 10*(BASE_RES - 1); i++){
    printf("%e %e\n", res.xs[i], res.ys[i]);
  }

  return 0;
}
