/**
 * A program that implements an algorithm for finding 
 * the largest power of 2 smaller than or equal to a 
 * non-negative integer n.
 * @author Minghao Shan
 * @version September 21, 2017
 */
#include <iostream>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

uint max_square( uint number, uint & count )
{
    uint max = number;
    uint remains = max & (max - 1);
    count++;
    while( remains != 0 )
    {
      max = remains;
      remains = max & (max - 1);
      count++;
    }
    return max; 
}

int main( int argc, char* argv[] )
{
    if(argc != 2)
    {
        cout << "Usage: " << argv[0] <<
            " n, n is the number of elements in the array" << endl;
        exit( 1 );
    }
    uint num = stoul( argv[1] );
    uint count = 0;
    uint largest = max_square( num, count );

    cout << largest <<" is the largest power of  2 that is less than " << num << endl;
    cerr << count << endl;
    return 0;
}