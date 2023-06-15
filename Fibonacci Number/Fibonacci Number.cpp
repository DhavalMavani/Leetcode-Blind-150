class Solution
{
public:
    int fibb(int n)
    {
        if (n == 1 || n == 0)
        {
            return n;
        }
        return fibb(n - 1) + fibb(n - 2);
    }
    int fib(int n)
    {

        return fibb(n);
    }
};