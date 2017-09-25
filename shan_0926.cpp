/**
 * A program that implements an algorithm for finding 
 * the largest power of 2 smaller than or equal to a 
 * non-negative integer n.
 * @author Minghao Shan
 * @version September 21, 2017
 */
#include <iostream>
#include <cstdint>
#include <iostram>
#include <vector>
using namespace std;

uint max_square( uint number, uint & count )
{
    uint i = n;
    uint j = i & (i - 1);
    count++;
    while( j != 0 )
    {
      i = j;
      j = i & (i - 1);
      count++;
    }
    return i; 
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

    cout << largest <<" is the largest power of  2 that is less than " << argc << endl;
}