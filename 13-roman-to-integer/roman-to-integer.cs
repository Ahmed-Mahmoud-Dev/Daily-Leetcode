public class Solution
{
    public int RomanToInt(string s)
    {
        var equivalent = new Dictionary<char, int>();
        equivalent['I'] = 1;
        equivalent['V'] = 5;
        equivalent['X'] = 10;
        equivalent['L'] = 50;
        equivalent['C'] = 100;
        equivalent['D'] = 500;
        equivalent['M'] = 1000;

        int res = 0, n = s.Length, cur;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                if (s[i] == 'I' && s[i + 1] == 'V')
                    cur = 4;
                else if (s[i] == 'I' && s[i + 1] == 'X')
                    cur = 9;
                else if (s[i] == 'X' && s[i + 1] == 'L')
                    cur = 40;
                else if (s[i] == 'X' && s[i + 1] == 'C')
                    cur = 90;
                else if (s[i] == 'C' && s[i + 1] == 'D')
                    cur = 400;
                else if (s[i] == 'C' && s[i + 1] == 'M')
                    cur = 900;
                else
                    cur = equivalent[s[i]];

                if (cur != equivalent[s[i]]) i++;
            }
            else
                cur = equivalent[s[i]];
            res += cur;
        }

        return res;
    }
}