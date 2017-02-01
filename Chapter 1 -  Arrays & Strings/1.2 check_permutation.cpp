#include <iostream>
using namespace std;
bool check_permutation(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if (n1 != n2)
        return false;
    else
    {
        int i, ch1[256] = {0}, ch2[256] = {0};  // assuming ACSII character set
        for (i = 0; i < n1; i++)
            ch1[s1[i]]++;
        for (i = 0; i < n2; i++)
            ch2[s2[i]]++;
        for (i = 0; i < 256; i++)
        {
            if (ch1[i] != ch2[i])
                return false;
        }
        return true;
    }
}
int main()
{
    string s1 = "abcdefgh", s2 = "ebgachdf", s3 = "abcdefgi";
    cout << s1 << " and " << s2 << " are" << (check_permutation(s1, s2) ? " " : " not ") << "permutations of each other\n";
    cout << s1 << " and " << s3 << " are" << (check_permutation(s1, s3) ? " " : " not ") << "permutations of each other";
    return 0;
}