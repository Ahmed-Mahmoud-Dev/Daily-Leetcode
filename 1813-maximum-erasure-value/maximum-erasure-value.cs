public class Solution
{
    public int MaximumUniqueSubarray(int[] nums)
    {
        int n = nums.Length, len = (int)1e4 + 5, res = 0, sum = 0;
        bool[] freq = new bool[len];
        for (int i = 0, j = 0; i < n; i++)
        {
            while (freq[nums[i]])
            {
                freq[nums[j]] = false;
                sum -= nums[j];
                j++;
            }

            freq[nums[i]] = true;

            sum += nums[i];
            res = Math.Max(res, sum);
        }

        return res;
    }
}