#ifndef queue_h
#define queue_h

class Queue
{
private:
  int _queue[3];
  bool _checkForDuplicates(int value);
public:
	Queue();
	Queue(int val1, int val2, int val3);
	int getSize();
	int* getArrayPointer();
	int getHighestValue()
	void sort();
	void flip();
	void insert(int value);
	void remove(int value);
};

#endif
