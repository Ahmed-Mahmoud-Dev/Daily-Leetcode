public class Solution
{
    public string LongestCommonPrefix(string[] strs)
    {
        int minLen = int.MaxValue, n = strs.Length;
        for(int i=0; i<n; i++)
        {
            if(minLen >  strs[i].Length) minLen = strs[i].Length;
        }
        int indx = minLen;
        for(int i=0; i<minLen; i++)
        {
            for(int j=1; j<n; j++)
            {
                if (strs[j][i] != strs[j - 1][i])
                {
                    indx = i;
                    goto here;
                }
            }
        }

        here:
            return strs[0].Substring(0,indx);
    }
}