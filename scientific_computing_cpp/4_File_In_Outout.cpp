/*
Jonathan Urrutia 2020/10/26
Firs steps in C++
In and Output to files
To run it on terminal we use

g++ "fileName"
then we will open it with
./a.out

Another way to do it is as follow

g++ -o outputname filename.cpp
./outputname

in the terminal

./SampleCode > SampleOutput.txt

this writes output in the file instead of the terminal
*/

#include <iostream>
#include <cmath>
#include <cassert> //Helps control if the operations are made wioth the correct kind of data
                  // assert(a >= 0.0)  -> Checks if a is non negative. If it negative, the programm stops
                  // assert(std::isfinite(x)) if is a finite numerical value
                  // assert(std::isnan(x)) if is a numerical value
                  // in terminal g++ -DNDEBUG program.cpp deactives assert making the program faster.
#include <fstream> //To write on files

int main(int argc, char* argv[]){
float x, y;


std::cout << "Give values for x and y\n";
std::cin >> x >> y;

if(y==0){
  std::cerr << "Error - Division by zero\n";
  // Consol ERRor -> output just shown in the console, not in the file
}
else{
  // y != 0
  std::cout << x/y << "\n";
}

double vx[3] = {0.0, 1.0, 0.0};
double vy[3] = {0.0, 0.0, 1.0};
//std::ofstream write_output("0_Output.dat"); // This rewrites the file, leading to possible data loss
std::ofstream write_output("0_Output.dat", std::ios::app); // This concatenates the data into the file
assert(write_output.is_open());
for(int i = 0; i<= 2; i++){
  write_output << vx[i] << " " << vy[i] << "\n";
}
x = 1.8364238;
write_output.precision(3); // Significal digits
write_output << x << "\n";
write_output.precision(10);
write_output << x << "\n";

write_output.close();
// write_output.flush();  // to write on live, similar to  std::cout.flush();




  return 0;
}
