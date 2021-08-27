/*
Jonathan Urrutia 2020/10/26
Firs steps in C++
Importing data

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
#include <cassert>
#include <fstream>

int main (int argc, char* argv[]){
  double x[100], y[100];

  std::ifstream read_file("0_Output.dat");
  assert(read_file.is_open());
  /*
  for(int i = 0; i <= 6; i++){
    read_file >> x[i] >> y[i];
  }
*/
int i = 0;
while (!read_file.eof()) {
  read_file >> x[i] >> y[i];
  ++i;
}
read_file.close();
/*
read_file.clear();  //Thos rewinds the document so we can read it again... ot something like that
read_file.seekg(std::ios::beg);
*/



  return 0;
}
