/**
 *@author Andrew Gast
 *@file string.cpp
 *CS23001
 *
 *Implementation for string ADT
 */

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>

/******************************************************************\
 ************************** CONSTRUCTORS **************************
\******************************************************************/
/**
 * String()
 * @post str = ""
 * Empty string that is null terminated at first index
 */
String::String() {
  str = new char[1];
  str[0] = 0;
  string_size = 1;
}

/**
 * String(char)
 * @post str = "c"
 * Index 0 takes char c and null terminates after
 */
String::String(char cstr){
  str = new char[2];
  str[0] = cstr;
  str[1] = 0;
  string_size = 2;
}

/**
 * String(char*)
 * @post str = cstr
 * Fill string with character array
 */
String::String(const char * cstr){
  int pos = 0;               // # of chars in cstr

  while(cstr[pos] != 0){     // find end of cstr
    ++pos;
  }

  str = new char[pos + 1];
  string_size = pos + 1;
  for(int i = 0; i < pos + 1; ++i){
    str[i] = cstr[i];
  }
  str[pos] = 0;
}

/******************************************************************\
 ********************* HELPER CTOR & METHODS **********************
\******************************************************************/
/**
 * String(int)
 * @post str = ""
 * empty string of size: new_size
 */
String::String(int new_size) : string_size(new_size + 1){
  str = new char[new_size + 1];
  str[new_size] = 0;
}

/**
 * String(int, char[])
 * @post
 */
String::String(int new_size, const char * rhs) : String(new_size){
  for(int i = 0; i < new_size; ++i){
    if(rhs[i] == 0) break;
    str[i] = rhs[i];
  }
}

/**
 * reset_capacity
 */
void String::reset_capacity(int new_size){

  String temp(new_size, str);
  swap(temp);

  /*
  char * temp_str = new char[new_size + 1];
  string_size = new_size + 1;
  temp_str[string_size - 1] = 0;
  for(int i = 0; i< new_size + 1; ++i){
    temp_str[i] = str[i];
  }
  delete [] str;
  str = temp_str;
  */
}

/**
 * swap - helper for operator= & reset_capacity
 */
void String::swap(String& rhs) {

  int temp_size = string_size;
  string_size = rhs.string_size;
  rhs.string_size = temp_size;

  char * temp_str = str;
  str = rhs.str;
  rhs.str = temp_str;
}

/******************************************************************\
 *************************** BIG THREE ****************************
\******************************************************************/
/**
 * String - Copy constructor (1/3)
 * @post rhs.str = str
 */
String::String(const String& rhs) : String(rhs.capacity()){
  for(int i = 0; i < capacity(); ++i){
    str[i] = rhs.str[i];
  }
}

/**
 * String - Destructor (2/3)
 */
String::~String() {
  delete [] str;
}

/**
 * operator= - Assignment (3/3)
 */
String& String::operator=(String rhs) {
  /*
  if(capacity() < rhs.length()){
    int newsize = length() + rhs.length();
    reset_capacity(newsize);
  }
  */
  swap(rhs);
  return *this;
}

/******************************************************************\
 ************************ CLASS FUNCTIONS *************************
\******************************************************************/
/**
 * capacity
 * @return the max chars that can be stored (not including null term)
 */
int String::capacity() const{
  return string_size - 1;
}

/**
 * length
 * @returns the total number of chars in string
 */
int String::length() const{
  int size = 0;
  while(str[size] != 0){
    ++size;
  }
  return size;
}

/**
 * substr
 * return substring extracted from start position
 */
String String::substr(int start_pos, int count) const{
  if(count > length()){ // if count is larger than length, downsize count to length
    count = length();
  }
  if(start_pos == 0){ // if starting at 0, copy string and resize to count
    String result = *this;
    result.reset_capacity(count);
    return result;
  }

  String result(count);
  int j = 0;

  for(int i = start_pos; i < start_pos + count; ++i){
    if(str[i] == 0){ // return if end of str is reached
      result.reset_capacity(i - start_pos); // reset capacity when null term is found
      return result;
    }
    result[j] = str[i]; // fill substring
    ++j;
  }
  return result;
}

/**
 * find char
 * returns loc of first char found. -1 if it doesnt exist
 */
int String::find(char ch, int start_pos) const{
  for(int i = start_pos; i < length(); ++i){
    if(str[i] == ch){
      return i;
    }
  }
  return -1;
}

/**
 * find string
 * returns loc of starting point of found substring.
 * -1 if returned if substring does not exist
 */
int String::find(const String & s, int start_pos) const{
  /*
  int pass = 0; //counter to iterate through
  char ch = s.str[0];
  int first_ch = find(ch, start_pos); //index of first char in search string
  // if first char of string DNE, return -1
  if(first_ch == -1){
    return -1;
  }

  while(first_ch < length()){
    first_ch = find(ch, start_pos + pass); //increase start pos for find_ch by 1 with each failed pass
    // create temp string with acquired info
    String temp(substr(first_ch, length() - first_ch));
    int i = 0;
    while(s.str[i] == temp.str[i]){
      ++i;
      if(s.str[i] == 0){ //when search string reaches 0, all cases are matched
        return first_ch;
      }
    }
    ++pass; //if the substring is not found, increase pass by 1, which increases our starting index for the next pass
  }
  return -1;
  */

  if(length() >= s.length()){
    for(int i = start_pos, j = 0; i < length(); ++i, j=0){
      while(str[i + j] == s.str[j] && j <= s.length()){
        ++j;

        if(j == s.length()){
          return i;
        }
      }
    }
  }
  return -1;
}

/**
 * split
 * split for parsing input data
 */
std::vector<String> String::split(char ch) const{
  std::vector<String> result;
  String temp;
  //1 Error from 1 context
  for(int i = 0; str[i] != 0; ++i){

    if(str[i] != ch){ //Fill temp when delimeter is not next
      temp += str[i];

    }else{ //if delimeter, push temp into vector and resize temp
      result.push_back(temp);
      temp.reset_capacity(0);
      //String temp;
      if(str[i+1] == ch){
        //temp = "";
        result.push_back(temp);
        ++i;
      }
      //temp = str[i];
      //temp = str[++i];
    }
  }
  result.push_back(temp);
  return result;
}

/******************************************************************\
 *************************** SUBSCRIPT ****************************
\******************************************************************/
/**
 * operator[] - Mutator
 * @pre 0 <= i < length()
 * @return value = str[i]
 */
char& String::operator[](int i) {
  // Assert to ensure we are using an in-bound index
  //assert(i >= 0 && i < string_size);
  return str[i];
}

/**
 * operator[] - Accessor
 * @pre 0 <= i < length()
 * @post return value = str[i]
 */
char String::operator[](int i) const{
  // Assert to ensure we are using an in-bound index
  //assert(i >= 0 && i < string_size);
  return str[i];
}

/******************************************************************\
 ************************** RELATIONAL ****************************
\******************************************************************/
/**
 * operator<
 * Check if lhs and rhs are equal and not null terminated
 * When they are not equal, return true/false depending on lhs<rhs
 */
bool String::operator<(const String& rhs) const{
  int pos = 0;
  while((str[pos] != 0) && (rhs.str[pos] != 0) && (str[pos] == rhs.str[pos])){
    ++pos;
  }
  return str[pos] < rhs.str[pos];
}

/**
 * operator==
 * @post return true if equal or false if not equal
 * Check each index of lhs and rhs to ensure they are each equal
 */
bool String::operator==(const String& rhs) const{
  int pos = 0;
  while((str[pos] != 0) && (str[pos] == rhs.str[pos])){
    ++pos;
  }
  return str[pos] == rhs.str[pos];
}

/******************************************************************\
 ****************************** I/O *******************************
\******************************************************************/
/**
 * operator<< - output stream
 */
std::ostream& operator<<(std::ostream& out, const String& rhs){
  out << rhs.str;
  return out;
}

/**
 * operator>> - input stream
 */
std::istream& operator>>(std::istream& in, String& rhs){
  //String temp;
  char ch;
  // read in characters, skipping all whitespace, new line etc and fill string
  in >> ch;
  rhs += ch;
  while(in.get(ch) && (ch != ' ' || ch != '\n' || ch != '\t' || ch != '\r')){
    //temp += ch;
    //in.get(ch);
    rhs += ch;
    //in >> ch;
  }
  //rhs = temp;
  return in;
}

/******************************************************************\
 ************************* CONCATENATION **************************
\******************************************************************/
/**
 * operator+
 * Add together 2 Strings to concatenate them into one String
 * rhs is added to lhs after lhs null terminates
 */
String String::operator+(const String& rhs) const{
  int offset = length();
  String result(offset + rhs.length(), str);

  for(int i = 0; rhs[i] != 0; ++offset, ++i){
    result[offset] = rhs[i];
  }
  return result;
}

/**
 * operator+=
 * Add a String to lhs and store in lhs
 */
String& String::operator+=(String rhs){
  int offset = length();
  int newsize = offset + rhs.length();


  if(capacity() < rhs.length() + length()){
    //int newsize = length() + rhs.length();
    reset_capacity(newsize);
  }
  //reset_capacity(newsize);
  int pos = 0;

  while(rhs.str[pos] != 0){
    str[offset + pos] = rhs.str[pos];
    ++pos;
  }
  str[offset + pos] = 0;
  return *this;
}

/******************************************************************\
 ************************* FREE FUNCTIONS *************************
\******************************************************************/
/**
 * operator+
 * char* + String
 */
String operator+(const char * lhs, const String& rhs){
  String chr(lhs);
  return chr + rhs;
}

/**
 * operator+
 * char + String
 */
String operator+(char lhs, const String& rhs){
  String chr(lhs);
  return chr + rhs;
}

/**
 * operator==
 * char* == String ?
 */
bool operator==(const char * lhs, const String& rhs){
  String chr(lhs);
  return chr == rhs;
}

/**
 * operator==
 * char == String ?
 */
bool operator==(char lhs, const String& rhs){
  String chr(lhs);
  return chr == rhs;
}

/**
 * operator<
 * char* < String ?
 */
bool operator<(const char * lhs, const String& rhs){
  String chr(lhs);
  return chr < rhs;
}

/**
 * operator<
 * char < String ?
 */
bool operator<(char lhs, const String& rhs){
  String chr(lhs);
  return chr < rhs;
}

/**
 * operator<=
 * String <= String?
 */
bool operator<=(const String& lhs, const String& rhs){
  if((lhs < rhs) || (lhs == rhs)){
    return true;
  }
  return false;
}

/**
 * operator!=
 * String != String?
 */
bool operator!=(const String& lhs, const String& rhs){
  if(lhs == rhs){
    return false;
  }
  return true;
}

/**
 * operator>=
 * String >= String?
 */
bool operator>=(const String& lhs, const String& rhs){
  if((lhs > rhs) || (lhs == rhs)){
    return true;
  }
  return false;
}

/**
 * operator>
 * String > String?
 */
bool operator>(const String& lhs, const String& rhs){
  if(lhs < rhs || lhs == rhs){
    return false;
  }
  return true;
}
