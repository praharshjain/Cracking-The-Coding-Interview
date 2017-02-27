#include <iostream>
#define numberOfStacks 3
using namespace std;
class StackoverflowException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nStack overflow\n";
    }
};
class StackunderflowException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nStack underflow\n";
    }
};
template <class T>
class FixedMultiStack
{
  private:
    int stackSize, stackCapacity, *sizes;
    T *values;

  public:
    FixedMultiStack(int stackSize)
    {
        stackCapacity = stackSize;
        values = new T[stackSize * numberOfStacks];
        sizes = new int[numberOfStacks];
    }
    void push(int stackNum, T value)
    {
        if (isFull(stackNum))
        {
            StackoverflowException e;
            throw e;
        }
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
    }
    T pop(int stackNum)
    {
        if (isEmpty(stackNum))
        {
            StackunderflowException e;
            throw e;
        }
        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex];
        values[topIndex] = 0;
        sizes[stackNum]--;
        return value;
    }
    T peek(int stackNum)
    {
        if (isEmpty(stackNum))
        {
            StackunderflowException e;
            throw e;
        }
        return values[indexOfTop(stackNum)];
    }
    bool isEmpty(int stackNum)
    {
        return sizes[stackNum] == 0;
    }
    bool isFull(int stackNum)
    {
        return sizes[stackNum] == stackCapacity;
    }
    int indexOfTop(int stackNum)
    {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }
};
int main()
{
    FixedMultiStack<int> s(5);
    cout << "\nStack 1 is " << (s.isEmpty(1) ? "empty" : "not empty") << "\n";
    cout << "\nStack 2 is " << (s.isEmpty(2) ? "empty" : "not empty") << "\n";
    cout << "\nStack 3 is " << (s.isEmpty(3) ? "empty" : "not empty") << "\n";
    s.push(1, 5);
    s.push(1, 4);
    cout << "\nStack 1 is " << (s.isEmpty(1) ? "empty" : "not empty") << "\n";
    s.push(2, 1);
    s.push(2, 0);
    cout << "\nStack 2 is " << (s.isEmpty(2) ? "empty" : "not empty") << "\n";
    cout << "\nStack 3 is " << (s.isEmpty(3) ? "empty" : "not empty") << "\n";
    s.push(3, -2);
    s.push(3, 12);
    cout << "\nStack 3 is " << (s.isEmpty(3) ? "empty" : "not empty") << "\n";
    s.pop(3);
    s.pop(3);
    cout << "\nStack 3 is " << (s.isEmpty(3) ? "empty" : "not empty") << "\n";
}