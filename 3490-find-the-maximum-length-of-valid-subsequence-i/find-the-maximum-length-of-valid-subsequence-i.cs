public class Solution
{
    public int MaximumLength(int[] nums)
    {
        int n = nums.Length;

        int even = 0;
        foreach (int i in nums)
        {
            if (i % 2 == 0) even++;
        }

        int res = Math.Max(n-even, even);

        int cur = 0, prv = 0;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] % 2) != prv)
            {
                prv = 1 - prv;
                cur++;
            }
        }
        res = Math.Max(res, cur);

        cur = 0;
        prv = 1;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] % 2) != prv)
            {
                prv = 1 - prv;
                cur++;
            }
        }

        return Math.Max(res, cur);
    }
}