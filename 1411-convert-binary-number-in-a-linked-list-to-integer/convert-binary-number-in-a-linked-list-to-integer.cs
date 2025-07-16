public class Solution
{
    public int GetDecimalValue(ListNode head)
    {
        List<int> nums = new List<int>();
        while (head != null)
        {
            nums.Add(head.val);
            head = head.next;
        }

        int res = 0, two = 1;
        for (int i = nums.Count - 1; i >= 0; i--)
        {
            res += nums[i] * two;
            two *= 2;
        }

        return res;
    }
}