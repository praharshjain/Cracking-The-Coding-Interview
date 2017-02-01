#include <iostream>
using namespace std;
bool is_permutation_of_palindrome(string s)
{
    int i, odds = 0, n = s.size(), ch[256] = {0};   // assuming ACSII character set
    for (i = 0; i < n; i++)
        ch[s[i]]++;
    for (i = 0; i < 256; i++)
    {
        if (ch[i] % 2)
            odds++;
        if (odds > 1)
            return false;
    }
    return true;
}
int main()
{
    string s1 = "adcbacbd", s2 = "abcddcbs";
    cout << s1 << " is" << (is_permutation_of_palindrome(s1) ? " " : " not ") << " a permutation of a palindrome\n";
    cout << s2 << " is" << (is_permutation_of_palindrome(s2) ? " " : " not ") << " a permutation of a palindrome";
}