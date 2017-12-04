
/**
 * nqueens
 * @author original author Jon Beck
 * @author Minghao Shan
 * @version 11/27
 */
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "matrix.h"
using namespace std;
uint nodeCount = 0;
bool swapRow = false;

/**
  * This function checks to see if the current placement of queens on
  * the board is ok.  It is ok if no queen attacks another queen.  A
  * return of true means no conflict.  A return of false means at least
  * two queens conflict.  This function is designed for clarity, NOT
  * efficiency.  This function can be vastly improved.
  * @param board the n x n chessboard
  * @return the absence of a conflict with this board arrangement
  */

bool ok(const Matrix<bool> &board)
{
  uint n = board.numrows();

  // let row and col range over the entire board
  for (uint row = 0; row < n; row++)
    for (uint col = 0; col < n; col++)
      // if row and col designate a queen's position, see if it
      // conflicts with any other queen

      // let tryrow and trycol range over the entire board, looking
      // for a conflicting queen
      for (uint tryrow = 0; tryrow < n; tryrow++)
        for (uint trycol = 0; trycol < n; trycol++)
        {
          // if there's a queen at both row,col and tryrow,trycol
          if (board.at(row, col) && board.at(tryrow, trycol) &&
              // and it's not the same spot
              !(row == tryrow && col == trycol))
          {
            // first check if they're in the same column
            if (col == trycol)
              return false;
            // now check if they're in the sam row
            if (row == tryrow)
              return false;
            // now see if they're in the same "up" diagonal
            if (n - col + row == n - trycol + tryrow)
              return false;
            // and finally the same down diag
            if (row + col + 1 == tryrow + trycol + 1)
              return false;
          }
        }
  // if we made it here, then no two queens conflict
  return true;
}

/**
  * a simple procedure to output an ASCII art horizontal line with plus
  * signs where columns will intersect
  */
void hr(uint cols)
{
  cout << "    +";
  for (uint col = 0; col < cols; col++)
    cout << "---+";
  cout << endl;
}

/**
  * this function dumps the board to std output
  * @param board the board whose arrangement to dump
  */
void printBoard(const Matrix<bool> &board)
{
  hr(board.numrows());
  for (uint row = 0; row < board.numrows(); row++)
  {
    cout << ' ' << setw(2) << board.numrows() - row << " |";
    for (uint col = 0; col < board.numrows(); col++)
    {
      if (board.at(row, col))
        cout << " X |";
      else
        cout << "   |";
    }
    cout << endl;
    hr(board.numrows());
  }

  cout << "     ";
  for (uint col = 0; col < board.numrows(); col++)
    cout << ' ' << (char)('a' + col) << "  ";
  cout << endl;
}
/**
 * This method is responsible for swapping the vectors.
 * @param a first element index to swap
 * @param b second element indexto swao
 * @param vec The vector contaning elements.
 */
void swap(uint a, uint b, vector<uint> &vec)
{
  uint temp = vec[a];
  vec[a] = vec[b];
  vec[b] = temp;
}

/**
  * This is the recursive backtracking function. When called, k queens
  * have already been placed on the board in columns 0 .. k-1.  We're
  * trying to place the next queen in column k.
  * @param board the board on which to place the queen
  * @param vec the uint vector
  * @param x_coords vector that contains x coordinate of queen
  * @param y_coords vector that contains y coordinate of queen
  * @param n number of columns
  * @param row the row number
  */


void backtrack(Matrix<bool> &board, vector<uint> vec, vector<uint> x_coords, vector<uint> y_coords, uint n, uint row)
{
  if (n == 0)
  {
    cout << "Total number of nodes: " << nodeCount << endl;
    printBoard(board);
    exit(0);
  }
  for (uint i = 0; i < vec.size(); i++)
  {
    if (i == n)
    {
      break;
    }
    nodeCount++;
    // swap the first and the ith element and place the queen on the board
    swap(0, i, vec);
    uint current = vec[0];
    board.at(vec[0], row) = true;
    x_coords.push_back(row);
    y_coords.push_back(vec[0]);
    // did that cause a conflict?
    if (ok(board))
    {
      swap(0, n - 1, vec);
      backtrack(board, vec, x_coords, y_coords, n - 1, row + 1);
    }
    x_coords.pop_back();
    y_coords.pop_back();
    // reset the board
    board.at(current, row) = false;
    if (i + 1 >= n)
    {
      break;
    }
  }
}

/**
  * set up the board and start the backtracking algorithm at the
  * top of the search tree
  */
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " n" << endl;
    cout << "       where n is the number of queens to place" << endl;
    cout << "       on an n x n chessboard, with 0 < n < 26" << endl;
    exit(2);
  }

  uint n = stoul(argv[1]);

  //If the argument expression of this macro with functional form
  //compares equal to zero (i.e., the expression is false), a message
  //is written to the standard error device and abort is called,
  //terminating the program execution.
  assert(n > 0 && n < 26);

  // initialize a board with no queens
  Matrix<bool> board(n, n);
  for (uint row = 0; row < n; row++)
    for (uint col = 0; col < n; col++)
      board.at(row, col) = false;

  //init vector
  vector<uint> vec, x, y;
  for (uint i = 0; i < n; i++)
  {
    vec.push_back(i);
  }
  // start with column 0
  backtrack(board, vec, x, y, n, 0);
  cout << "No solution" << endl;
  exit(1);
}