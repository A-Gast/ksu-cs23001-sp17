//==============================================================================
// Basics for opening a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    
    bigint b1, b2, b3;
    in >> b1;
    in >> b2;
    while(!in.eof()){
      std::cout << "BigInt 1: " << b1 << '\n';
      std::cout << "BigInt 2: " << b2 << '\n';
      b3 = b1 + b2;;
      std::cout << "BigInt 1 + BigInt 2 = " << b3 << '\n' << '\n';
      in >> b1;
      in >> b2;
    }    
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
 
    in.close();
    return 0;
}
