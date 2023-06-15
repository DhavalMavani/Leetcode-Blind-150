class Solution
{
public:
    bool isPalindrome(int x)
    {

        long int rev = 0, temp = x;

        while (temp != 0)
        {

            rev = rev * 10 + temp % 10;
            temp = temp / 10;
        }
        if (rev == x && rev >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};