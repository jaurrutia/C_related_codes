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

// The order of the polynomial we are interpolating
#define ORDER 5

// This structure will contain the outpul of the interpolation process
// typedef allows us to give an alias to a type of input so it becomes more readable
// meantin that result = struct
// struct allows us to create vaiables that contain a lot of information. In this example, the
// result type consisit of two pointes xs and ys.
typedef struct result{
  float *xs; //pointer for memory managements?
  float *ys;
} result;

// Polynomiual interpolation
//given two sets of (x,y) points and a new x valie, return the interpoated y value
float interp(float *xs, float *ys, float x, int order){
    float y = 0, tmp;

    for( int i = 0; i < order; i++){
      tmp = ys[i];
      for(int j = 0; j < order; j++){
        if(j == i) continue; //If i = j, skips this step
        tmp *= (x - xs[j]) / (xs[i] - xs[j]);
      }
      y += tmp;
    }
    return y;
}


// Thie linear interpolation of all the data
result interpolate(float *xs, float *ys, int n, int order){
  float delta;
  result res;

  res.xs = malloc(10 * (n - 1) * sizeof(float)); // Assigns spaces in the memory fot 10(n-1) floats
  res.ys = malloc(10 * (n - 1) * sizeof(float));
  for(int i = 0; i< n-1; i++){
    for(int j = 0; j < 10; j++){
      delta = xs[i+1] - xs[i];
      res.xs[10*i+j] = xs[i] + 0.1 * ((float) j) * delta;
      if(i < n - order){
        res.ys[10*i+j] = interp(xs+i, ys+i, res.xs[10*i+j], order);
      }
      else{
        res.ys[10*i+j] = interp(xs+n-order, ys+n-order, res.xs[10*i+j], order);
      }
    }
  }
  // Extrapolation, It is just the same but we go beyond out data
  for(int j=0;j<10;j++)
  {
      res.xs[90+j] = xs[9]+0.1*((float) j)*delta;
      res.ys[90+j] = interp(xs+n-order, ys+n-order, res.xs[90+j], order);
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

  result res = interpolate(xs, ys, BASE_RES, ORDER+1); //Interpolate to 10x higher resolution

  for(int i = 0; i < 10*(BASE_RES - 1); i++){
    printf("%e %e\n", res.xs[i], res.ys[i]);
  }

  return 0;
}
