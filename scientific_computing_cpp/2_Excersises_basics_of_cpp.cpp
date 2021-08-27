/*
Jonathan Urrutia 2020/10/26
Firs steps in C++
Excersices of common calculations

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
#include <string>

int main(){

int int_1, int_2, i, j, k;
double v1[3], v2[3];
double dot, norm1, norm2, average;
double A[2][2] = {{1.,0.},{0.,1.}};
double B[2][2] = {{0.,1.},{1.,0.}};
double C[2][2], D[2][2], E[2][2];
int ave[5] = {34, 58, 57, 32, 43};

// C is the sum of matrices
// D is multiplication entry- entry
// E is matrix dot product. It might be usfull so se if there is a length operation in Cpp or C


std::cin >> int_1 >> int_2;
std::cout << "The product is " << int_1 * int_2 << "\n";

std::cout << "Give the entries of v1:\n";
for (i = 0; i <= 2; i++) {
  std::cin >> v1[i];
}
std::cout << "Give the entries of v2:\n";
for (i = 0; i <= 2; i++) {
  std::cin >> v2[i];
}

dot = norm1 = norm2 = 0;
for (i = 0; i <= 2; i++) {
  dot +=  v1[i] * v2[i];
  norm1 += v1[i] * v1[i];
  norm2 += v2[i] * v2[i];
}
norm1 = sqrt(norm1);
norm2 = sqrt(norm2);

std::cout <<  "The dot product of the two vectors is" << dot << "\n";
std::cout <<  "The norm of v1 is " << norm1 << "\n";
std::cout <<  "The norm of v2 is " << norm2 << "\n";

for(i = 0; i<= 1; i++){
  for(j = 0; j<= 1; j++){
    C[i][j] = A[i][j] + B[i][j];
    D[i][j] = A[i][j] * B[i][j];
    E[i][j] = 0;
      for(k = 0; k<= 1; k++){
      E[i][j] +=  A[i][k] * B[k][j];
    }
  }
}

std::cout <<  "The C matrix is \n";
for(i = 0; i<= 1; i++){
  for(j = 0; j<= 1; j++){
    std::cout << C[i][j] << " ";
  }
  std::cout << "\n";
}

std::cout <<  "The D matrix is \n";
for(i = 0; i<= 1; i++){
  for(j = 0; j<= 1; j++){
    std::cout << D[i][j] << " " ;
  }
  std::cout << "\n";
}

std::cout <<  "The E matrix is \n";
for(i = 0; i<= 1; i++){
  for(j = 0; j<= 1; j++){
    std::cout << E[i][j] << " ";
  }
  std::cout << "\n";
}

average = 0.;
for ( i = 0; i <= 4; i++) {
  average += (double) ave[i];
}

std::cout << "The averge is " << average/5. << "\n";




}
