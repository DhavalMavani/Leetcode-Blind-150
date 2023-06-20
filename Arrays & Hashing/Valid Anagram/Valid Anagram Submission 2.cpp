class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        unordered_map<char, int> ump;

        if (s.length() != t.length())
        {
            return false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            ump[s[i]] += 1;
            ump[t[i]] -= 1;
        }

        for (auto i : ump)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};