/**
 *@author Andrew Gast
 *@file bigint.cpp
 *CS23001
 *
 *Implementation for bigint ADT
 */

#include <iostream>
#include "bigint.hpp"

//**************BIGINT CONSTRUCTORS*************************
////////////////////////////////////////////////////////////

///////DEFAULT CTOR///////////////////////////////
// creates new bigint object of MAX_SIZE, sets 0
bigint::bigint(){
  for (int i=0; i < MAX_SIZE; ++i){
    value[i] = 0;
  }
}
///////INTEGER CTOR///////////////////////////////
// passes to default ctor to set all vlues to 0
// then fills array from least sig digit onward
bigint::bigint(int int_value) : bigint(){
  for(int i = 0; i < MAX_SIZE; ++i){
    value[i] = int_value % 10;
    int_value /= 10;
  }
}
///////CHAR CTOR//////////////////////////////////
// passes to default ctor to set all values to 0
// search char array until null identifier '\0' is located
// once located, the array is filled backwards
// this sets the least sig digit of char array to index 0
bigint::bigint(const char char_value[]) : bigint(){
  int i=0;
  int u=0;
  while(char_value[i] != '\0'){
    ++i;
  }
  --i;
  while(i>=0){
    value[u] = char_value[i] - '0';
    --i;
    ++u;
  }
}

//**************BIGINT CLASS FUNCTIONS**********************
////////////////////////////////////////////////////////////

///////DEBUG_PRINT////////////////////////////////
// prints each element of bigint array with "|" between
void bigint::debug_print(std::ostream& out) const{
  out << "|";
  for (int i = MAX_SIZE - 1; i >= 0; i--){
    out << value[i] << "|";
  }
  out << '\n';
}
///////TIMES_DIGIT////////////////////////////////
// multiply bigint and a single digit integer between 0-9
bigint bigint::times_digit(int num){
  bigint result;
  int carry = 0;
  int tmp = 0;
  for(int i = 0; i < MAX_SIZE; i++){
    tmp = (value[i] * num) + tmp; // multiply index by num and add carried over digit
    carry = tmp % 10; // split to pull the least sig digit
    tmp /= 10; // pull the carry-over digit to be added
    result.value[i] = carry; // add the single digit pulled
  }
  return result;
}
///////TIMES_10//////////////////////////////////
// shift left base 10, 10^n equals n shifts left
// shift until index of [num] is reached, then place zeros
bigint bigint::times_10(int num){
  bigint result;
  for(int i = MAX_SIZE - 1 - num; i >= 0; i--){ // shift until num index is reached
    result.value[num + i] = value[i];
  }
  for(int k = 0; k < num; k++){ // place zeros after shift
    result.value[k] = 0;
  }
  return result;
}
//**************BIGINT OVERLOADED OPERATORS*****************
////////////////////////////////////////////////////////////

///////OPERATOR << ///////////////////////////////
// overload << to access private member value[] from class
// skip all leading zeros to find first sig digit
// print out the bigint array, new line every 70 characters
std::ostream& operator<<(std::ostream& out, const bigint& bi){
  int u = 1; //used to count lines to 70
  int i = MAX_SIZE -1;
  while((bi.value[i] == '\0') || (bi.value[i] == 0)){
    if(i == 0)
      break;
    --i;
  }
  for(int c = i; c >= 0; c--){ // new line at 70 characters
    if(u > 70){
      u = 0;
      out << '\n';
    }
    out << bi.value[c];
    u++;
  }
  return out;
}
///////OPERATOR >> ///////////////////////////////
// overload >> to accept file i/o and user input
std::istream& operator>>(std::istream& in, bigint& bi){
  char char_array[MAX_SIZE + 1];
  char chr; //Temporary holder for char
  
  for(int i = 0; i < MAX_SIZE + 1; i++){
    in >> chr; //Read first character of input and places in chr
    if(chr == ';'){ //If this char is ';' insert null term and break for loop
      char_array[i] = '\0';
      break;
    }
    char_array[i] = chr; //Insert char into array
  }

  bi = bigint(char_array); //Fill bigint with char array from the loop
  return in;
}

///////OPERATOR == ///////////////////////////////
// compares 2 bigint objects to check if they are equal
// if every index value matches, return true
bool bigint::operator==(const bigint& bi) const{
  for(int i = 0; i < MAX_SIZE; i++){
    if(value[i] != bi.value[i])
      return false;
  }
  return true;
}
///////OPERATOR + ////////////////////////////////
// adds 2 bigint objects and returns result
bigint bigint::operator+(const bigint& bi) const{
  bigint result;
  int carry = 0; //Used to carry a digit when the index being added > 9

  for(int i = 0; i < MAX_SIZE; i++){
    int add = value[i] + bi.value[i] + carry;
    
    if(add > 9) //Carry 1 to index+1
      carry = 1;
    else 
      carry = 0;

    result.value[i] = add%10; //Extract the ones digit
  }
  return result;
}
///////OPERATOR * ////////////////////////////////
// multiplies 2 bigint objects and returns result
// utilize helper times_digit and times_10 functions
// 
bigint bigint::operator*(bigint rhs){
  bigint product;
  bigint temp;
  for(int i = 0; i < MAX_SIZE; i++){
    temp = times_digit(rhs.value[i]);
    product = product + temp.times_10(i);
  }
  return product;
}
///////OPERATOR [] ///////////////////////////////
// returns value from whichever index chosen
int& bigint::operator[](int index){
  return value[index];
}
