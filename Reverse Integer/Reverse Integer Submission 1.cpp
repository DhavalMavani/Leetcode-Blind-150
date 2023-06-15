class Solution
{
public:
    int reverse(int x)
    {

        long int rev_num = 0;
        rev_num = x % 10;
        x = x / 10;

        while (x != 0)
        {
            rev_num = 10 * rev_num + x % 10;
            x = x / 10;
        }

        if (rev_num >= pow(-2, 31) && rev_num <= pow(2, 31) - 1)
        {
            return rev_num;
        }
        else
        {
            return 0;
        }
    }
};