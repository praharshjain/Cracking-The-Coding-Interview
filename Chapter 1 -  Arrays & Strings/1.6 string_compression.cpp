#include <bits/stdc++.h>
using namespace std;
string compress(string s)
{
    string res = ""; //compressed string
    int repeat = 0, len = s.size();
    for (int i = 0; i < len; i++)
    {
        repeat++;
        if (i + 1 >= len || s[i] != s[i + 1])
        {
            res += s[i];
            stringstream ss;
            ss << repeat;
            res += ss.str();
            repeat = 0;
        }
    }
    return res.size() < len ? res : s;
}
int main()
{
    string s = "aabcccccaaa";
    cout << compress(s);
}