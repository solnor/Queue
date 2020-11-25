#include "Queue.h"
Queue upwardsQueue(9,4,6);
Queue downwardsQueue;
int *queuePointer = 0;
int queueSize = 0;

void setup() {
  Serial.begin(9600);
  downwardsQueue.insert(4);
  downwardsQueue.insert(3);
  downwardsQueue.insert(7);
  downwardsQueue.remove(3);
  upwardsQueue.sort();
  downwardsQueue.sort();
  downwardsQueue.flip();
  queuePointer = downwardsQueue.getArrayPointer();
  queueSize = downwardsQueue.getSize();
}

void loop() {
  for (int i = 0; i < queueSize; i++)
  {
    Serial.print(*(queuePointer+i));
  }
  Serial.println();
  delay(50);
}
