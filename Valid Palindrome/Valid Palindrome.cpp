class Solution
{
public:
    bool checkPalindrome(string::iterator l, string::iterator r)
    {
        if (l >= r)
        {
            return true;
        }
        if (*l != *r)
        {
            return false;
        }
        return checkPalindrome(l + 1, r - 1);
    }
    bool isPalindrome(string s)
    {

        string str;
        for (auto i : s)
        {
            if (isalnum(i))
            {
                str += i;
            }
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        return checkPalindrome(str.begin(), str.end() - 1);
    }
};