/**
 *@author Andrew Gast
 *@file bigint.hpp
 *CS23001
 *
 *Header file for bigint.cpp
 */

#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP

const int MAX_SIZE = 500;

//**************BIGINT CLASS DEFINITIONS********************
////////////////////////////////////////////////////////////

class bigint{

public:
  //CONSTRUCTORS//
  bigint();
  bigint(int integer_value);
  bigint(const char char_string[]);

  //FUNCTIONS
  void debug_print(std::ostream& out) const;
  bigint times_digit(int num);
  bigint times_10(int num);

  //OVERLOADS
  bool operator==(const bigint& bi) const;
  bigint operator+(const bigint& bi) const;
  bigint operator*(bigint rhs);
  int& operator[](int index);
  friend std::ostream& operator<<(std::ostream& out, const bigint& bi);
  friend std::istream& operator>>(std::istream& in, bigint& bi);

private:
  int value[MAX_SIZE];

};
////////////////////////////////////////////////////////////
#endif
