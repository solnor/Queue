#ifndef queue_h
#define queue_h

class Queue
{
private:
  int _queue[4];
  bool _checkForDuplicates(int value);
  int _highestFloor;
public:
	Queue();
	Queue(int val1, int val2, int val3, int val4);
	int getSize();
	int* getArrayPointer();
	int getHighestValue();
	int getLowestValue();
	void sort();
	void flip();
	void insert(int value);
	void remove(int value);
};

#endif
