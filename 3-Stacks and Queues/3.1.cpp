#include <iostream>
using namespace std;
class MultiStack
{
  int no_of_stack = 3;
  int stackCapacity;
  int *stackArray;
  int *StackCapacityUsed;
public:
  MultiStack(int stackCapacity)
  {
    this->stackCapacity = stackCapacity;
  }
  bool isEmpty(int stackNum) const
  {
    return (StackCapacityUsed[stackNum] == 0);
  }
  bool isFull(int stackNum) const
  {
    return (StackCapacityUsed[stackNum] == stackCapacity);
  }
  int indexOfTop(int stackNum) const
  {
    int startIndex = stackNum*stackCapacity;
    int capacity = StackCapacityUsed[stackNum];
    return (startIndex + capacity - 1);
  }
  int top(int stackNum) const
  {
    if(isEmpty(stackNum))
      cout<<"Stack "<<stackNum<<" is empty"<<endl;
    else
      return stackArray[indexOfTop(stackNum)];
  }
  void push(int stackNum, int val)
  {
    if(isFull(stackNum))
      cout<<"Stack "<<stackNum<<" is full"<<endl;
    else
    {
      stackCapacity[stackNum]++;
      stackArray[indexOfTop(stackNum)] = val;
    }
  }
  void pop(int stackNum)
  {
    if(isEmpty(stackNum))
      cout<<"Stack "<<stackNum<<" is empty"<<endl;
    else
    {
      int topIndex = indexOfTop(stackNum);
      stackArray[topIndex] = 0;
      StackCapacityUsed[stackNum]--;
    }
  }
};
int main()
{

  return 0;
}
