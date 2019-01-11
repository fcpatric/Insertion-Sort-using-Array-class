/// Lab 6, Insertion Sort using Array class
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// Array.h

#ifndef ARRAY_H
#define ARRAY_H

// When debugging, use #define DEBUG_ARRAY above your #include Array line.
// When done debugging, comment out #define DEBUG_ARRAY for better performance.
// The constructor and the changeSize function can cause an exception to be thrown if out of heap memory

#include <iostream>
using std::ostream;

#include <string>
using std::string;

template<class DataType>
class Array
{
private:
  DataType *elements;
  int capacity;
  DataType dud;
  int errorCode;
  int firstIndex;
  int lastIndex;

public:
  Array( int size );
  inline DataType& operator[]( int index );
  void changeSize( int newSize );
  inline int length() const;
  string err() const;

  int binarySearch( const DataType& target );

  void insertionSort();

  template<class DT>
	friend ostream& operator<<(ostream& out, Array<DT>& a);
};

#include "Array.cpp"

#endif // ARRAY_H
