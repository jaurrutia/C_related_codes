/*
Jonathan Urrutia
2020/12/22

Hello world in CUDA-C
*/

#include <stdio.h> //Why not use this one??
//#include <iostream>

__global__ void kernel( void ){
}

int main( void ) {
 kernel<<<1,1>>>();
 printf( "Hello, World!\n" );
  return 0;
}
