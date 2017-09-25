/**
 * algorithm max_element adapted from Levitin page 61
 * @author Jon Beck
 * @version 17 September 2017
 */

 #include <cstdint>
 #include <cstdlib>
 #include <iostream>
 #include <vector>
 using namespace std;
 
 uint max_element( const vector<uint> & a, uint & count_ops )
 {
   uint maxval = a.at( 0 );
   for( uint i = 1; i < a.size(); i++ )
   {
     count_ops++;
     if( a.at( i ) > maxval )
     {
       maxval = a.at( i );
     }
   }
   return maxval;
 }
 
 int main( int argc, char* argv[] )
 {
   if( argc != 2 )
   {
     cout << "Usage: " << argv[0] <<
       " n, n the number of elements in the array" << endl;
     exit( 1 );
   }
   srand( time( 0 ) );
 
   uint n = stoul( argv[1] );
   vector<uint> values;
 
   for( uint i = 0; i < n; i++ )
   {
     uint value = rand();
     values.push_back( value );
   }
 
   uint count = 0;
   uint largest = max_element( values, count );
 
   cout << RAND_MAX << " is the maximum random value" << endl;
   cout << largest << " is the largest value in the array" << endl;
   cerr << values.size() << "\t" << count << endl;
   return 0;
 }