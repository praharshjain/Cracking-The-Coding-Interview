#include <iostream>
using namespace std;
bool has_unique_char(string s)
{
    if (s.size() > 256)    // assuming ACSII character set
        return false;
    bool arr[256] = {false}; 
    int i, n = s.size();
    for (i = 0; i < n; i++)
    {
        if (arr[s[i]])
            return false;
        else
            arr[s[i]] = true;
    }
    return true;
}
int main()
{
    cout << has_unique_char("abcdefgh") << "\n";
    cout << has_unique_char("abaevh");
    return 0;
}