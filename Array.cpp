/// Lab 6, Insertion Sort using Array class
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// Array.cpp

#include <string>
using std::string;

// Error code -- use powers of 2
// 0  No error.
// 1  Nonpositive size passed into constructor.
// 2 Invalid index was used.
// 4 Nonpositive new size passed into changeSize function

template <class DataType>
Array<DataType>::Array( int size )
{
  if( size < 1 )
  {
    capacity = 1;
    firstIndex  = 0;
    lastIndex = capacity - 1;
    errorCode = 1; // nonpositive size
  }

  else
  {
    capacity = size;
    firstIndex = 0;
    lastIndex = capacity - 1;
    errorCode = 0; // no error
  }

  elements = new DataType[capacity];
}

template <class DataType>
inline DataType& Array<DataType>::operator[]( int index )
{
  #ifdef DEBUG_ARRAY

  if( index < 0 || index >= capacity )
  {
    errorCode |=2; // invalid index
    return dud;
  }

  #endif // DEBUG_ARRAY

  return elements[index];
}

template <class DataType>
void Array<DataType>::changeSize( int newSize )
{
  if( newSize < 1 )
  {
    errorCode |= 4; //nonpositive new size
    return;
  }

  DataType *newArray = new DataType[newSize];

  int limit = (newSize > capacity) ? capacity : newSize;

  for( int i = 0; i < limit; i ++ )
    newArray[i] = elements[i];

  delete [] elements;

  elements = newArray;

  capacity = newSize;
}

template <class DataType>
inline int Array<DataType>::length() const
{
  return capacity;
}

template <class DataType>
string Array<DataType>::err() const
{
  if( errorCode == 0 )
    return "No error.\n";

  string errorMessage = "";

  if( errorCode & 1 ) // nonpositive size
  {
    errorMessage += "Nonpositive size passed into constructor, so\n";
    errorMessage += "the capacity was set to 1 by default.\n";
  }

  if( errorCode & 2 ) // invalid index
    errorMessage += "Index out of range.\n";

  if( errorCode & 4 ) // nonpositive new size in changeSize
  {
    errorMessage += "Nonpositive size passed into changeSize, so\n";
    errorMessage += "the size of the array was not changed.\n";
  }

  return errorMessage;
}

template <class DataType>
int Array<DataType>::binarySearch( const DataType& target )
{
  if( firstIndex > (capacity - 1) || lastIndex < 0 || capacity == 0 )
  {
    firstIndex = 0;
    lastIndex = capacity - 1;
    return -1;
  }

  int middleIndex = (firstIndex + lastIndex) / 2;

  if( elements[middleIndex] == target )
  {
    firstIndex = 0;
    lastIndex = capacity - 1;
    return middleIndex;
  }

  else if( elements[middleIndex] < target )
  {
    firstIndex = middleIndex + 1;
    binarySearch( target );
  }

  else if( elements[middleIndex] > target )
  {
    lastIndex = middleIndex - 1;
    binarySearch( target );
  }
}

template <class DataType>
void Array<DataType>::insertionSort()
{
  DataType temp;

  for(int i = 1; i < capacity; i++)
  {
    temp = elements[i];
    int j = i - 1;

    for(; j >= 0 && elements[j] > temp; j--)
      elements[j + 1] = elements[j];

    elements[j + 1] = temp;
  }
}

template <class DT>
ostream& operator<<(ostream& out, Array<DT>& a)
{
	for (int i = 0; i < a.length(); i ++)
		out << a[i] << "\n";

	return out;
}
