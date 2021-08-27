/*
Jonathan Urrutia
2020/12/21

Scientific computing with CUDA course

Fourier transform

we need to run it as follows :

gcc 3-Numerical-Int.c -lm
*/

#include <time.h>
#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#define N (2 << 12)   // << is a bit shift operation
                      // 2 << 12 is in binary  2 = 10 -> 2^12 = 1000000000000 (deciimal = binary)
                      // This is basically N = 2^12 but is suposed to be more efficient.

// discrete fourier transform
void dft(float complex *F, float complex *f, int n);
// fast fourier tranform
void fft(float complex *F, float complex *f, int n, int stride);
// dirac-delta function
void dirac_delta(float complex *input);
//sine function initial value
void sine(float complex *input);
//sinc function intial value
void sinc(float complex *input);
// http://show.docjava.com/pub/document/jot/v8n6.pdf
//void centering(float complex *input);


// Main
int main(int argc, char *argv[]){
  // We use pointers so we only use this slots in the memory
  float complex *x = malloc(N*sizeof(float complex));
  float complex *ft_x = malloc(N*sizeof(float complex));

  sinc(x);
  //dft(ft_x, x, N);
  fft(ft_x, x, N, 1);
// We still need to implement a shift of the data :c

  for(int i = 0; i < N; i++)
    printf("%e %e %e\n", creal(x[i]), creal(ft_x[i]), cimag(ft_x[i]) );

    return 0;
}






// Functions

/*
//Centering th output  http://show.docjava.com/pub/document/jot/v8n6.pdf
void centering(float complex *input){
  int s = 1;
  for(int i = 0; i < N; i++){
    s = -s;
    input[i] *= s;
  }
}
*/

// Discrete fourier transform
void dft(float complex *F, float complex *f, int n){
  for(int i = 0; i < n; i++){
    F[i] = 0. + 0. * I;
    for(int j = 0; j < n; j++){
      F[i] += f[j] * cexp(I * 2. * M_PI * i * j / n);
    }
  }
}

// Fast Fourier transform
void fft(float complex *F, float complex *f, int n, int stride){
  float complex t;

  if(n == 1){
    F[0] = f[0];
  }
  else{
    //Split the array and recursively process every 2*stride elemtns
    fft(F, f, n/2, 2*stride);
    fft(F+n/2, f+stride, n/2, 2*stride);
    for(int i = 0; i < n/2; i++){
      t = F[i];
      F[i] = t + cexp(I*2.*M_PI* i/n)*F[i+n/2];
      F[i+n/2] = t - cexp(I*2.*M_PI* i/n)*F[i+n/2];
    }
  }
}

// dirac-delta function
void dirac_delta(float complex *input){
  for(int i = 0; i < N; i++)
    input[i] = 0.;
  input[0] = 1.;  // Usually this is an infinity, but here we put their integral (1)
}

//sine function intial value
void sine(float complex *input){
  for(int i = 0; i < N; i++)
      input[i] = csin(8.*((float)i)*M_PI/N);
}

//sinc function initial value
void sinc(float complex *input){
  for(int i = 0; i < N; i++)
    input[i] = csin(10.*((float)i)*M_PI/N) / (10.*((float)i)*M_PI/N);
  input[0] = 1;
}
