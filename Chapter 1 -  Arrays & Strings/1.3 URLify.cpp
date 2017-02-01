#include <bits/stdc++.h>
using namespace std;
void replace_spaces(char *s)
{
    int i, count = 0, len = strlen(s);
    for (i = 0; i < len; i++)
    {
        if (s[i] == ' ')
            count++;
    }
    int newlen = len + (2 * count);
    s[newlen] = 0;
    for (i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[newlen - 1] = '0';
            s[newlen - 2] = '2';
            s[newlen - 3] = '%';
            newlen -= 3;
        }
        else
        {
            s[newlen - 1] = s[i];
            newlen--;
        }
    }
}
int main()
{
    char s[] = "hello world";
    replace_spaces(s);
    cout << s;
    return 0;
}