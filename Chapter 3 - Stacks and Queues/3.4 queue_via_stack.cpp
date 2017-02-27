#include <iostream>
using namespace std;
class CollectionFullException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nCollection is full\n";
    }
};
class CollectionEmptyException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nCollection is empty\n";
    }
};
template <class T>
class Stack
{
  private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int top;

  public:
    Stack()
    {
        top = -1;
    }

    void Push(const T element)
    {
        if (top >= MAX_SIZE)
        {
            CollectionFullException e;
            throw e;
        }
        else
            data[++top] = element;
    }

    T Pop()
    {
        if (top <= -1)
        {
            CollectionEmptyException e;
            throw e;
        }
        else
            return data[top--];
    }

    int Size()
    {
        if (top <= -1)
        {
            return 0;
        }
        else
        {
            return top + 1;
        }
    }

    bool isEmpty()
    {
        return (top <= -1) ? true : false;
    }
};
template <class T>
class Queue_via_Stack
{
  private:
    Stack<T> in, out;

  public:
    void Enqueue(T element)
    {
        in.Push(element);
    }
    T Dequeue()
    {
        if (!out.isEmpty())
            return out.Pop();
        else
        {
            while (!in.isEmpty())
                out.Push(in.Pop());
            return out.Pop();
        }
    }
};
int main()
{
    Queue_via_Stack<int> q;
    q.Enqueue(2);
    q.Enqueue(8);
    q.Enqueue(-4);
    cout << q.Dequeue() << "\n";
    cout << q.Dequeue() << "\n";
    q.Enqueue(0);
    q.Enqueue(1);
    cout << q.Dequeue() << "\n";
    cout << q.Dequeue() << "\n";
    cout << q.Dequeue() << "\n";
}