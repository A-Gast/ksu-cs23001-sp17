// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times_digit(0);

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9999);

        // Test 
        bi = bi.times_digit(9);

        // Verify
        assert(bi == 89991);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("100000000000000000000");

        // Test 
        bi = bi.times_digit(3);

        // Verify
        assert(bi == "300000000000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("1555555555555555555555555555555555555");

        // Test 
        bi = bi.times_digit(0);

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("1555555555555555555555555555555555555");

        // Test 
        bi = bi.times_digit(1);

        // Verify
        assert(bi == "1555555555555555555555555555555555555");
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;

}
