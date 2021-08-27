/*
Jonathan Urrutia 2020/10/26
Firs steps in C++
Newton-Raphson

To run it on terminal we use

g++ "fileName"
then we will open it with
./a.out

Another way to do it is as follow

g++ -o outputname filename.cpp
./outputname


*/
#include <iostream> //Input Output STRAMing
#include <cmath>

int main(){
/*
f(x) = exp(x) + pow(x,3) - 5
f'(x) = exp(x) + 3 * pow(x,2)
x[i] = x[i-1] - f(x)/f'(x)
x_0 = 0
*/
int N = 100;
int i;
// float x[100];
float f, df, x_next, x_prev, dummy;

/*
x[0] = 0;
for(i = 0; i<= N-2; i++){
  f = exp(x[i]) + pow(x[i],3) - 5;
  df = exp(x[i]) + 3 * pow(x[i],2);
  x[i+1] = x[i] - f / df;
  std::cout << "x = " << x[i+1] << "\n";
}
*/

i = 0;
x_prev = dummy =  0.;
x_next = 10.;
while (fabs(x_next - x_prev) > 1E-12 && i<N ){
  ++i;
  x_prev = dummy;

  f = exp(x_prev) + pow(x_prev,3) - 5;
  df = exp(x_prev) + 3 * pow(x_prev,2);
  dummy = x_next = x_prev - f / df;
}
  if (i == N)
    std::cout << "Not convergence achieved\n";
  std::cout << "x = " << x_next << "\n";






  return 0;
}
