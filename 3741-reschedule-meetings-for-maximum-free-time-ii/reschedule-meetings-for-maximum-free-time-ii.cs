public class Solution
{
    public int MaxFreeTime(int eventTime, int[] startTime, int[] endTime)
    {
        int n = startTime.Length;

        int[] mx1 = new int[n + 1], mx2 = new int[n + 1], dif = new int[n + 1];
        mx1[0] = dif[0] = startTime[0];
        mx2[n] = eventTime - endTime[n - 1];

        int res;
        for (int i = 1; i < n; i++)
        {
            dif[i] = startTime[i] - endTime[i - 1];
            mx1[i] = Math.Max(mx1[i - 1], dif[i]);
        }
        dif[n] = mx2[n];
        mx1[n] = Math.Max(mx1[n - 1], dif[n]);

        res = mx1[n];

        for (int i = n - 1; i > 0; i--)
        {
            mx2[i] = Math.Max(mx2[i + 1], startTime[i] - endTime[i - 1]);
        }
        mx2[0] = Math.Max(mx2[1], startTime[0]);

        int len;
        for (int i = 0; i < n; i++)
        {
            res = Math.Max(res, dif[i] + dif[i + 1]);
            if (i - 1 >= 0) res = Math.Max(res, dif[i] + dif[i - 1]);

            len = endTime[i] - startTime[i];
            if ((i + 2 <= n && mx2[i + 2] >= len) || (i - 1 >= 0 && mx1[i - 1] >= len))
                res = Math.Max(res, dif[i] + dif[i + 1] + len);

        }

        return res;
    }
}