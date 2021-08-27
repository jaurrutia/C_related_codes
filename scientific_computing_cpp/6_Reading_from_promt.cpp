/*
Jonathan Urrutia 2020/12/21
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

FOR THIS CASE WE WILL OPNE IT AS FOLLOWS
  ./a.out 100 5.0
*/

#include <iostream>
#include <cstdlib>

int main (int argc, char* argv[]){
  std::cout << "Number of command line aruguments = "
            << argc << "\n";


// argc are string given by us in the pront and then we storage them in the next loop
  for (int i = 0; i < argc; i++){
    std::cout << "Argument" << i << " = " << argv[i];
    std::cout << "\n";
  }


// We chang our data (in strings) to integers and floats
  std::string program_name = argv[0];
  int number_of_nodes = atoi(argv[1]): //Array TO Integer (atoi)
  double conductivity = atof(argv[2]); //Array TO Float (atof)
  std::cout << "Program name = " << program_name << "\n";
  std::cout << "Number of nodes = " << number_of_nodes;
  std::cout << "\n";
  std::cout << "Conductivity = " << conductivity << "\n";


  return 0;
}
