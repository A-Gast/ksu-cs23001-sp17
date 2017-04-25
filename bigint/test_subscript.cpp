// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(123456);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 123456);
        assert(digit == 5);
    }
    {
        // Setup
        bigint bi("1234567890123");

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == "1234567890123");
        assert(digit == 8);
    }
    {
        // Setup
        bigint bi("123456789");

        // Test 
        int digit = bi[8];

        // Verify
        assert(bi    == "123456789");
        assert(digit == 1);
    }
    {
        // Setup
        bigint bi("12345678901234567890");

        // Test 
        int digit = bi[5+5];

        // Verify
        assert(bi    == "12345678901234567890");
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi("1234567890123");

        // Test 
        int digit = bi[20-10];

        // Verify
        assert(bi    == "1234567890123");
        assert(digit == 3);
    }
    {
        // Setup
        bigint bi("012541206999987");

        // Test 
        int digit = bi[15];

        // Verify
        assert(bi    == "012541206999987");
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi("012541206999987");

        // Test 
        int digit = bi[16];

        // Verify
        assert(bi    == "012541206999987");
        assert(digit == '\0');
    }
    {
        // Setup
        bigint bi;

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 0);
        assert(digit == 0);
    }
    /*
    {
        // Setup
      bigint bi("1234567890");

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == "1234567890");
		assert(digit == 6); // Should Fail
    }
    */
    /*
    {
        // Setup
        bigint bi;

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 0);
        assert(digit == 1); // Should fail
    }
    */
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}
