/*
Jonathan Urrutia
2020/12/21

Scientific computing with CUDA course

Interpolation with Lagrange polynamials
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of points in the original datasheet
#define BASE_RES 10

// This structure will contain the outpul of the interpolation process
// typedef allows us to give an alias to a type of input so it becomes more readable
// meantin that result = struct
// struct allows us to create vaiables that contain a lot of information. In this example, the
// result type consisit of two pointes xs and ys.
typedef struct result{
  float *xs; //pointer for memory managements?
  float *ys;
} result;

// Linear interpolation  y = mx + b function
//given two sets of (x,y) points and a new x valie, return the linear-interpoated y value
float interp(float y0, float y1, float x0, float x1, float x){
    return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}


// Thie linear interpolation of all the data
result interpolate(float *xs, float *ys, int n){
  float delta;
  result res;

  res.xs = malloc(10 * (n - 1) * sizeof(float)); // Assigns spaces in the memory fot 10(n-1) floats
  res.ys = malloc(10 * (n - 1) * sizeof(float));
  for(int i = 0; i< n-1; i++){
    for(int j = 0; j < 10; j++){
      delta = xs[i+1] - xs[i];
      res.xs[10*i+j] = xs[i] + 0.1 * ((float) j) * delta;
      res.ys[10*i+j] = interp(ys[i], ys[i+1], xs[i], xs[i+1], res.xs[10*i+j]);
    }
  }
  return res;
}

int main(){
  // generate our input data (as imple sine curve)
  float xs[BASE_RES], ys[BASE_RES];

  for(int i = 0; i < BASE_RES; i++){
    xs[i] = 4. * M_PI*((float) i)/BASE_RES;
    ys[i] = sin(xs[i]);
  }

  result res = interpolate(xs, ys, BASE_RES); //Interpolate to 10x higher resolution

  for(int i = 0; i < 10*(BASE_RES - 1); i++){
    printf("%e %e\n", res.xs[i], res.ys[i]);
  }

  return 0;
}
