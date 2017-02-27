#include <bits/stdc++.h>
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
struct node
{
    T value;
    T substack_min; // min of substacks
    struct node *next;
};
template <class T>
class Stack
{
  private:
    static const int MAX_SIZE = 100;
    struct node<T> data[MAX_SIZE];
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
            StackoverflowException e;
            throw e;
        }
        else
        {
            data[++top].value = element;
            if (top > 0)
                data[top].substack_min = min(element, data[top - 1].substack_min);
            else
                data[top].substack_min = element;
        }
    }

    T Pop()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
        }
        else
        {
            return data[top--].value;
        }
    }

    T Top()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
        }
        else
        {
            return data[top].value;
        }
    }
    T min_stack()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
        }
        else
        {
            return data[top].substack_min;
        }
    }
    int Size()
    {
        if (top <= -1)
        {
            StackunderflowException e;
            throw e;
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

int main()
{
    Stack<int> s;
    if (s.isEmpty())
    {
        cout << "Stack is empty\n";
    }
    s.Push(100);
    cout << "Current min : " << s.min_stack() << "\n";
    s.Push(20);
    cout << "Current min : " << s.min_stack() << "\n";
    s.Push(0);
    cout << "Current min : " << s.min_stack() << "\n";
    s.Push(-10);
    cout << "Current min : " << s.min_stack() << "\n";
    s.Push(46);
    cout << "Current min : " << s.min_stack() << "\n";
    s.Push(15);
    cout << "Current min : " << s.min_stack() << "\n";
    s.Pop();
    s.Pop();
    s.Pop();
    cout << "Current min : " << s.min_stack() << "\n";
    return 0;
}