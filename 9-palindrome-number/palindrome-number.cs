public class Solution
{
    public bool IsPalindrome(int x)
    {
        int reverse = 0, tmp = x;

        while (tmp > 0)
        {
            reverse = reverse * 10 + tmp % 10;
            tmp /= 10;
        }
        
        return (x == reverse);
    }
}