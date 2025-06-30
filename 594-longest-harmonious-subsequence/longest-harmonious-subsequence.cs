public class Solution
{
    public int FindLHS(int[] nums)
    {
        Array.Sort(nums);
        int n = nums.Length, res = 0;
        
        for(int i=0; i<n; i++)
        {
            int l = i, r = n - 1, m, ans = -1, cur = nums[i]+1;
            while(l <= r)
            {
                m = (r + l) / 2;
                if (nums[m] <= cur)
                {
                    l = m + 1;
                    ans = m;
                }
                else
                {
                    r = m - 1;
                }
            }

            if (nums[ans] - nums[i] == 1) res = int.Max(res, ans-i+1);
        }

        return res;
    }
}