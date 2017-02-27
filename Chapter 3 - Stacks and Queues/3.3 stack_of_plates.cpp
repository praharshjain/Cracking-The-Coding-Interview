#include <bits/stdc++.h>
#define MAX 100
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
class SetOfStacks
{
  private:
    unsigned int capacity, stacks, current;
    vector<T> data[MAX];

  public:
    SetOfStacks(int n = 5)
    {
        capacity = n;
        stacks = 1;
        current = 0;
    }
    void push(T element)
    {
        if (data[current].size() >= capacity)
        {
            if (current < MAX - 1)
            {
                current++;
                stacks++;
            }
            else
            {
                StackoverflowException e;
                throw e;
            }
        }
        data[current].push_back(element);
    }
    T pop()
    {
        if (data[current].size() <= 0)
        {
            if (current > 0)
            {
                current--;
                stacks--;
            }
            else
            {
                StackunderflowException e;
                throw e;
            }
        }
        T temp = data[current].back();
        data[current].pop_back();
        return temp;
    }
    T popAt(int index) //follow-up question
    {
        if (index > current)
        {
            cout << "No such index exists.";
            return;
        }
        else
        {   data[current].back();
        }
    }
};
int main()
{
    SetOfStacks<int> s(3); //set capacity of each sub-stack = 3
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(-3); //start next stack
    s.push(4);
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
}