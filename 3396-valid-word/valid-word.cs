public class Solution
{
    public bool IsValid(string word)
    {
        if(word.Length < 3) return false;

        int vowels = 0;
        char cur;
        int cnst = 0;
        for (int i=0; i<word.Length; i++)
        {
            cur = char.ToLower(word[i]);
            if (!(cur <= 'z' && cur >= 'a') && !(cur <= '9' && cur >= '0')) return false;
            if((cur <= 'z' && cur >= 'a'))
            {
                if (cur == 'a' || cur == 'i' || cur == 'o' || cur == 'e' || cur == 'u') vowels++;
                else cnst++;
            }
        }

        if(vowels == 0 || cnst == 0) return false;

        return true;
    }
}