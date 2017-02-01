#include <iostream>
using namespace std;
bool is_substr(string s1, string s2)
{
    return (s1.find(s2) != std::string::npos);
}
bool is_rotation(string s1, string s2)
{
    int len = s1.size();
    if (len == s2.size() && len > 0)
    {
        return is_substr(s1 + s1, s2);
    }
}
int main()
{
    string s1 = "waterbottle", s2 = "erbottlewat", s3 = "erbottlewae";
    cout << s1 << " is" << (is_rotation(s1, s2) ? " " : " not ") << "rotation of " << s2 << "\n";
    cout << s1 << " is" << (is_rotation(s1, s3) ? " " : " not ") << "rotation of " << s3;
}