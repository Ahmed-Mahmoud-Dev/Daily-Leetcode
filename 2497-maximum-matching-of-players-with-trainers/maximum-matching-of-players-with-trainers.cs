public class Solution
{
    public int MatchPlayersAndTrainers(int[] players, int[] trainers)
    {
        Array.Sort(players);
        Array.Sort(trainers);

        int n = players.Length, m = trainers.Length;
        int i=0, j=0, res = 0;
        while (i<n && j<m)
        {
            if (players[i] <= trainers[j])
            {
                i++;
                j++;
                res++;
            }
            else j++;
        }

        return res;
    }
}
