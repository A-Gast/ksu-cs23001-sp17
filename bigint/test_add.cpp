// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include <climits>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture (0+0=0)
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);

	// Output
	std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (1+0=1)
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (1+1=2)
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //----------------------------------------------------
      // Setup fixture (7+4=11) (1,1,2)
      bigint left(7);
      bigint right(4);
      bigint result;

      //Test
      result = left + right;

      // Verify
      assert(left == 7);
      assert(right == 4);
      assert(result == 11);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (10+4=14) (2,1,2)
      bigint left(10);
      bigint right(4);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10);
      assert(right  == 4);
      assert(result == 14);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (4+10=14) (1,2,2)
      bigint left(4);
      bigint right(10);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 4);
      assert(right  == 10);
      assert(result == 14);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (10+11=21) (2,2,2)
      bigint left(10);
      bigint right(11);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 10);
      assert(right  == 11);
      assert(result == 21);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (101+9=110) (3,1,3)
      bigint left(101);
      bigint right(9);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 101);
      assert(right  == 9);
      assert(result == 110);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }    
    {
      //------------------------------------------------------
      // Setup fixture (9+101=110) (1,3,3)
      bigint left(9);
      bigint right(101);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 101);
      assert(result == 110);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (11+100=111) (2,3,3)
      bigint left(11);
      bigint right(100);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 11);
      assert(right  == 100);
      assert(result == 111);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //------------------------------------------------------
      // Setup fixture (100+11=111) (3,2,3)
      bigint left(100);
      bigint right(11);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 100);
      assert(right  == 11);
      assert(result == 111);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left(9855);
      bigint right(5);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 9855);
      assert(right == 5);
      assert(result == 9860);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left("5");
      bigint right(10);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "5");
      assert(right == 10);
      assert(result == 15);

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left(10000);
      bigint right("5000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 10000);
      assert(right == "5000000");
      assert(result == "5010000");

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left("999999999999999");
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "999999999999999");
      assert(right == 1);
      assert(result == "1000000000000000");

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left("55555555555555555555");
      bigint right("11111111111111111111");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "55555555555555555555");
      assert(right == "11111111111111111111");
      assert(result == "66666666666666666666");

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left("55555555555555555555555555555555555");
      bigint right("11111111111111111111111111111111111");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "55555555555555555555555555555555555");
      assert(right == "11111111111111111111111111111111111");
      assert(result == "66666666666666666666666666666666666");

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left(INT_MAX);
      bigint right(500);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == INT_MAX);
      assert(right == 500);
      assert(result == "2147484147");

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }
    {
      //-----------------------------------------------------
      // Setup fixture
      bigint left(500);
      bigint right(INT_MAX);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 500);
      assert(right == INT_MAX);
      assert(result == "2147484147");

      // Output
      std::cout << left << " + " << right << " = " << result << '\n';
    }    
    
    std::cout << "Done with testing addition." << std::endl;
}
