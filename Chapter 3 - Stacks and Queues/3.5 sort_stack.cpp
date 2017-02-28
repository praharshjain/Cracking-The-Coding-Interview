#include <bits/stdc++.h>
using namespace std;
template <class T>
void sort_stack(vector<T> *s)
{
    vector<T> r;
    while ((*s).size())
    {
        T temp = (*s).back();
        (*s).pop_back();
        while (r.size() && r.back() > temp)
        {
            (*s).push_back(r.back());
            r.pop_back();
        }
        r.push_back(temp);
    }
    while (r.size())
    {
        (*s).push_back(r.back());
        r.pop_back();
    }
}
int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    sort_stack(&v);
    while (v.size())
    {
        cout << v.back() << " ";
        v.pop_back();
    }
    return 0;
}