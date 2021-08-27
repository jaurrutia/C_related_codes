/*
Jonathan Urrutia
2020/12/21

Scientific computing with CUDA course

Numerical integration
we need to run it as follows :

gcc 3-Numerical-Int.c -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simpson_rule(double* x, double* y, int n);

// ARGuments Count and ARGyments Vector
// Parameters passed via the line command
int main(int argc, char *argv[]){
  //The program takes one argument, just the number of points to integrate over
  if(argc != 2){
    printf("Input number of data points\n");
    return -1;
  }

  int n_points = atoi(argv[1]); // array to integer -> Reads the given Number
  // To avoid a 2nd order error term, we use an odd number of points

  if(n_points % 2 == 0){
    n_points += 1;
  }

  // Generate our input data
  double xs[n_points], ys[n_points];
  for( int i = 0; i < n_points; i++){
    xs[i] = M_PI*((double) i)/(n_points-1);
    ys[i] = sin(xs[i]);
  }

  printf("%e\n", 2.0 - simpson_rule(xs, ys, n_points) );
  return 0;
}



/*
 Functions
*/

double simpson_rule(double* x, double* y, int n){
  double delta, y_int = 0;

  for( int i = 0; i < n-2; i+= 2){
    delta = x[i+2] - x[i];
    y_int += (delta/6.) * (y[i+2] + 4. * y[i+1] + y[i]);
  }
  return y_int;
}
