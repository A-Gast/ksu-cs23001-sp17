
#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>
#include <vector>

/**
 * @invariant str[length()] == 0
 *         && length()      == capacity()
 *         && capacity()    == stringSize - 1
 */
class String {
private:
    // helper constructors and methods
    String(int);
    String(int, const char *);
    void reset_capacity (int);

    char * str;

    // size includes NULL terminator
    int string_size;

public:

    // constructor: empty string, String('x'), and String("abcd")
    String();
    String(char);
    String(const char *);

    // copy ctor, destructor, constant time swap, and assignment
    String(const String &);
    ~String();
    void     swap          (String &);
    String & operator=     (String);

    // subscript: accessor/modifier and accessor
    char & operator[](int);
    char   operator[](int) const;

    // max chars that can be stored (not including null terminator)
    int capacity()      const;
    // number of char in string
    int length  ()      const;
    // return substring from start position with a count of characters
    String substr(int, int) const;
    // location of first character found. -1 if not found
    int find(char, int) const;
    // location of starting point of substring found. -1 if not found
    int find(const String &, int) const;
    // split for parsing input data
    std::vector<String> split(char) const;

    // concatenation
    String   operator+ (const String &) const;
    String & operator+=(String);

    // relational methods
    bool operator==(const String &)  const;
    bool operator< (const String &)  const;

    // i/o
    friend std::ostream& operator<<(std::ostream &, const String &);
    friend std::istream& operator>>(std::istream &, String &);

};

// free functios for concatenation and relational
String operator+       (const char *,   const String &);
String operator+       (char,           const String &);
bool   operator==      (const char *,   const String &);
bool   operator==      (char,           const String &);
bool   operator<       (const char *,   const String &);
bool   operator<       (char,           const String &);
bool   operator<=      (const String &, const String &);
bool   operator!=      (const String &, const String &);
bool   operator>=      (const String &, const String &);
bool   operator>       (const String &, const String &);

#endif
