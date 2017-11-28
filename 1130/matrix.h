#ifndef MATRIX_H
#define MATRIX_H

#include <algorithm>
#include <cassert>
#include <cstdint>
using namespace std;

/**
 * A generic 2-dimensional array class
 * @author Jon Beck
 * @version 15 September 2017
 */
template <class Object>
class Matrix
{
 public:
  /**
   * Constructor, specifying number of both rows and columns
   * @param rows the number of rows
   * @param cols the number of columns
   */
  Matrix( uint rows, uint cols );

  /**
   * Access to an element to allow modification
   * @param row the row index
   * @param col the column index
   * @return reference to the element at that position
   */
  Object & at( uint row, uint col );

  /**
   * Constant access to an element
   * @param row the row index
   * @param col the column index
   * @return constant reference to the element at that position
   */
  const Object & at( uint row, uint col ) const;

  /**
   * Destructor to free allocated memory
   */
  ~Matrix();

  /**
   * Copy constructor to make 1-1 copy of existing matrix
   * @param m the existing matrix to be copied
   */
  Matrix( const Matrix<Object> & m ); // Copy constructor

  /**
   * Disallow the rvalue copy constructor
   */
  Matrix( const Matrix<Object> && m ) = delete;

  /**
   * Assignment operator to make 1-1 copy of existing matrix
   * @param m the existing matrix to be copied
   */
  Matrix & operator= ( const Matrix<Object> & m ); // Assignment operator

  /**
   * Disallow the rvalue assignment operator
   */
  Matrix & operator= ( const Matrix<Object> && m ) = delete;

  /**
   * Accessor to determine how many rows are in the matrix
   * @return the number of rows in the matrix
   */
  uint numrows() const;

  /**
   * Accessor to determine how many columns are in the matrix
   * @return the number of columns in the matrix
   */
  uint numcols() const;

 private:
  uint rows;
  uint cols;
  Object* data;
};

template <class Object>
Matrix<Object>::Matrix( uint rows, uint cols )
: rows( rows ), cols( cols )
{
  data = new Object[ rows * cols ];
}

template <class Object>
Matrix<Object>::Matrix( const Matrix<Object> & rhs )
: rows( rhs.rows ), cols( rhs.cols )
{
  data = new Object[ rows * cols ];
  copy( rhs.data, rhs.data + rows * cols, data );
}

template <class Object>
Matrix<Object> & Matrix<Object>::operator= ( const Matrix<Object> & rhs )
{
  assert (rows == rhs.rows && cols == rhs.cols );
  copy( rhs.data, rhs.data + rows * cols, data );
  return *this;
}

template <class Object>
Matrix<Object>::~Matrix()
{
  delete[] data;
}

template <class Object>
Object & Matrix<Object>::at( uint row, uint col )
{
  assert( row < rows && col < cols );
  return data[ cols * row + col ];
}

template <class Object>
const Object & Matrix<Object>::at( uint row, uint col ) const
{
  assert( row < rows && col < cols );
  return data[ cols * row + col ];
}

template <class Object>
uint Matrix<Object>::numrows() const
{
  return rows;
}

template <class Object>
uint Matrix<Object>::numcols() const
{
  return cols;
}
#endif