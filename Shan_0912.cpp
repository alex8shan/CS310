

#include <algorithm>
#include "Matrix.h"
using namespace std;

bool is_connected( const Matrix<uint8_t> &graph )
{
    vector< bool > reached( graph.numcols, false );

    queue< uint8_t > to_be_explored;
    to_be_explored.push( 0 );
    while ( !to_be_explored.empty() )
    {
        uint8_t current_node = to_be_explored.front();
        to_be_explored.pop();

        reached.at( current_node ) = true;
        for ( uint16_t col_num = 0; col_num <= graph.numcols(); col_num++ )
        {
            for ( uint8_t adjacent : graph.at(row_num, col_num) )////What the fuck???
            {
                if ( !reached.at(adjacent) )
                {
                    to_be_explored.push(adjacent);
                }
            }
        }
    }
    return find( reached.begin(), reached.end(), false ) == reached.end();
}

int main()
{
    // create matrix
    Matrix(5, 5) graph;
    graph.at(0, 1) = true;
}