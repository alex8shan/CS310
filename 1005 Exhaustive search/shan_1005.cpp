/**
 * exhaustive-search discrete knapsack
 * @author originally written by Jon Beck
 * @author Minghao Shan
 * @version 10/ 04/ 2017
 */
#define FIELD_WIDTH 6
#include <climits>
#include <iomanip>
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;


/**
 * C++ has floating-point exponentiation named pow in the cmath library,
 * but no integer exponentiation. This is unsigned integer exponentiation.
 * @param base the base which is being raised to a power
 * @param exp the exponent to which to raise the base
 * @return base raised to the exp power
 */
uint ipow(uint base, uint exp)
{
  if( base == 0 )
    return 1;
  uint result = 1;
  while( exp > 0 )
  {
    if( (exp & 1) == 1 )
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}


/**
 * This method searchs through the entire super set of the input using exhaustive search,
 * and exclude the permutations that is out of the capacity.
 * @ param weights The vector containing the weight of the input
 * @ param values The vector containing the values of the input
 * @ param capacity The maximum capacity.  
 */
void search(vector <uint> weights, vector <uint> values, uint capacity)
{
  uint weight_sum = 0;
  uint value_sum = 0;
  uint element_num = 0;
  uint input_size = weights.size();
  uint count = 0;

  for( int i = 0; i < (ipow (2, weights.size())); i++)
  {
    weight_sum = 0;
    value_sum = 0;
    element_num = 0;

    for (int j = 0; j < weights.size(); j ++ )
    {
      //The basic operation is getting counted
      count++;
      //The comparasion is the basic operation
      if(((i >> j) & 1) == 1)
      {
        weight_sum += weights.at(j);
        value_sum +=values.at(j);
      }
    }
    element_num = element_num * 2 + 1;
    cout.width((20 - element_num));
    if(weight_sum <= capacity)
    {
      cout << weight_sum << " ";
      cout.width(10);
      cout << value_sum << endl;
    }
    else
    {
      cout<< weight_sum << " ";
      cout.width(10);
      cout << "NF" << endl;  
    }
  }

  cout << "Input size is "<< input_size << endl;
  cout.width(5);
  cout << "Count is " << count << endl;
}


int main()
{

  uint capacity;
  cin >> capacity;

  vector<uint> weights;
  vector<uint> values;  

  while( ! cin.eof() )
  {
    uint weight;
    uint value;
    cin >> weight >> value;
    if( ! cin.eof() )
    {
      weights.push_back( weight );
      values.push_back( value );
    }
  }
search( weights, values, capacity );
  return 0;
}