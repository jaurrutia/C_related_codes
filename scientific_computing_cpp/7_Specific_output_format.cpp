/*
Jonathan Urrutia 2020/12/21
Firs steps in C++
Exporting data

To run it on terminal we use

g++ "fileName"
then we will open it with
./a.out

Another way to do it is as follow

g++ -o outputname filename.cpp
./outputname

in the terminal
*/

#include <iostream>
#include <fstream>

int main (int argc, char* argv[]){
  std::ofstream write_file("0_OutputFormated.dat");
  // write numbers as +x.<13digits>e+00 (width 20)
  write_file.setf(std::ios::scientific);
  write_file.setf(std::ios::showpos);
  write_file.precision(13);

  double x = 3.4, y = 0.0000855, z = 984.424;
  write_file << x << " " << y << " " << z << "\n";

  write_file.close();

  return 0;
}
