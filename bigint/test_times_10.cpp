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
        bigint bi(3);

        // Test 
        bi = bi.times_10(0);

        // Verify
        assert(bi == 3);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(30);

        // Test 
        bi = bi.times_10(1);

        // Verify
        assert(bi == 300);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times_10(0);

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(5000);

        // Test 
        bi = bi.times_10(5);

        // Verify
        assert(bi == "500000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(123456);

        // Test 
        bi = bi.times_10(8);

        // Verify
        assert(bi == "12345600000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("500000000000000000000");

        // Test 
        bi = bi.times_10(0);

        // Verify
        assert(bi == "500000000000000000000");
    }    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(123);

        // Test 
        bi = bi.times_10(100);

        // Verify
        assert(bi == "1230000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}
