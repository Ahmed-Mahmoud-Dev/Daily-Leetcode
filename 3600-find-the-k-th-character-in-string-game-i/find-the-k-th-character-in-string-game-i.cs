public class Solution
{
    public char KthCharacter(int k)
    {
        var sb = new StringBuilder();

        sb.Append("a");
        int lg = (int)Math.Log2(k) + 1;
        for(int i=0; i <= lg; i++)
        {
            int len = sb.Length;
            for (int j=0; j<len; j++) sb.Append((char)(sb[j]+1));
        }

        return sb[k - 1];
    }
}