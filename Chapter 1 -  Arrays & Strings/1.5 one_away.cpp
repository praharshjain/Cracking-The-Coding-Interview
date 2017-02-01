#include <iostream>
using namespace std;
int abs(int x)
{
    return (x >= 0 ? x : -x);
}
bool is_one_away(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if (abs(n1 - n2) > 1)
        return false;
    else
    {
        int i, diff = 0, ch1[256] = {0}, ch2[256] = {0}; // assuming ACSII character set
        for (i = 0; i < n1; i++)
            ch1[s1[i]]++;
        for (i = 0; i < n2; i++)
            ch2[s2[i]]++;
        for (i = 0; i < 256; i++)
            diff += abs(ch1[i] - ch2[i]);
        return (diff <= 2);
    }
}
int main()
{
    string s1 = "pale", s2 = "ple", s3 = "bale", s4 = "bake";
    cout << s1 << " and " << s2 << " are" << (is_one_away(s1, s2) ? " " : " not ") << "one edit away\n";
    cout << s1 << " and " << s3 << " are" << (is_one_away(s1, s3) ? " " : " not ") << "one edit away\n";
    cout << s1 << " and " << s4 << " are" << (is_one_away(s1, s4) ? " " : " not ") << "one edit away\n";
}