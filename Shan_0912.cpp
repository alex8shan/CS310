#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

#include "Matrix.h"
using namespace std;

bool is_connected( const Matrix<bool> &graph )
{
    vector< bool > reached( graph.numcols(), false );

    queue< uint16_t > to_be_explored;
    to_be_explored.push( 0 );
    while ( !to_be_explored.empty() )
    {
        uint16_t current_node = to_be_explored.front();
        to_be_explored.pop();
        uint16_t row_num = 0;

        reached.at( current_node ) = true;
        for ( uint16_t col_num = 0; col_num < graph.numcols(); col_num++ )
        {
            if(graph.at(row_num, col_num))
            {
                uint16_t adjacent = col_num;
                if ( !reached.at( adjacent) )
                {
                    to_be_explored.push( adjacent );
                }
            }
        }
        row_num++;
    }
    return find( reached.begin(), reached.end(), false ) == reached.end();
}

int main()
{

    Matrix <bool> graph (4,4);
    graph.at(0, 1) = true;
    graph.at(0, 2) = true;
    graph.at(0, 3) = true;
    graph.at(1, 0) = true;
    graph.at(1, 3) = true;
    graph.at(2, 0) = true;
    graph.at(3, 0) = true;
    graph.at(3, 1) = true;

    cout<<"first test " <<boolalpha << is_connected( graph ) << endl;

    
    Matrix <bool> graph1(4,4);
    graph1.at(0, 1) = true;
    graph1.at(1, 0) = true;
    graph1.at(2, 3) = true;
    graph1.at(3, 2) = true;

    cout<<"second test " <<boolalpha << is_connected( graph ) << endl;
}