public class Solution
{
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {
        int[] merge = new int[n + m];

        int c = 0;
        for (int i = 0, j = 0; j < n || i < m;)
        {
            if (j == n || (i<m && nums1[i] <= nums2[j]))
            {
                merge[c] = nums1[i];
                i++;
                c++;
            }
            else
            {
                merge[c] = nums2[j];
                c++;
                j++;
            }
            Console.WriteLine(merge[c - 1]);
        }

        Array.Copy(merge, nums1, merge.Length);
    }
}