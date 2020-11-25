#include "Arduino.h"
#include "Queue.h"

//Constructor. Initializes _queue with default values.
Queue::Queue()
  :_queue{-1,-1,-1}
{
}
//Constructor which initializes _queue with user-specified values.
Queue::Queue(int val1, int val2, int val3)
  :_queue{val1,val2,val3}
{
}

//Returns a pointer to the first element in the _queue array
int* Queue::getArrayPointer()
{
  int* ptr = &_queue[0];
	return ptr;
}

//Returns the size of _queue
int Queue::getSize()
{
  return sizeof(_queue)/sizeof(_queue[0]);
}

//Gets the highest value in the queue array
int Queue::getHighestValue()
{
	highestVal = -1;
	for (int i = 1; i<getSize(); i++)
	{
		highestVal = _queue[i]>highestVal ? _queue[i] : highestVal;
	}
	return highestVal;
}

//Sorts the _queue array with the insertion sort algorithm
void Queue::sort()
{
  int key = 0;
  int j = 0;
  for (int i = 1; i<getSize(); i++)
  {
    key = _queue[i];
    j = i-1;
    while(j>=0 && _queue[j]>key)
    {
      _queue[j+1] = _queue[j];
      j--;
    }
    _queue[j+1] = key;
  }
}

//Swaps two and two elements in the queue at the time. Loops through half of the array and swaps with the the elements in the other half iteratively
void Queue::flip()
{
  //In the case the length of the array is even, the function should loop through half of the elements. If it's odd, it should loop through one less element.
  int _iterations = (getSize()%2==0 ? getSize()/2 : (getSize()-1)/2);
  int _lowIndexValue = 0;
  int _highIndexValue = 0;
  for(int i = 0; i<_iterations; i++)
  {
    _lowIndexValue = _queue[i];
    _highIndexValue = _queue[getSize()-1-i];
    _queue[i] = _highIndexValue;
    _queue[getSize()-1-i] = _lowIndexValue;
  }
}

//Loops through the array to check for duplicates. Returns true if a duplicate is found, false otherwise.
bool Queue::_checkForDuplicates(int value)
{
  for(int i = 0; i<getSize(); i++)
  {
    if(_queue[i]==value)
    {
      return true;
    }
  }
  return false;
}
//Inserts an element to an available location if the value of the element isn't already in the array.
//Elements with a value of -1 are considered available.
void Queue::insert(int value)
{
  if(!_checkForDuplicates(value))
  {
    for(int i = 0; i<getSize(); i++)
    {
      if(_queue[i]==-1)
      {
        _queue[i] = value;
        //Available location found, no need to check the rest of the array
        break;
      }
    }
  }
}
//Removes an element with a specified value from the _queue array.
void Queue::remove(int value)
{
  for(int i = 0; i<getSize();i++)
  {
    if(_queue[i]==value)
    {
      _queue[i] = -1;
      break;
    }
  }
}
