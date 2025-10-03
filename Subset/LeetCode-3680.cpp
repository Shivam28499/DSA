class Solution
{
public:
    vector<vector<int>> generateSchedule(int n)
    {
        if (n <= 4)
            return {};
        vector<vector<int>> game;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    game.push_back({i, j});
                }
            }
        }

        vector<vector<int>> ans;
        while (game.size() > 0)
        {
            vector<vector<int>> temp;
            for (int i = 0; i < game.size(); i++)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(game[i]);
                    continue;
                }
                int lastHomeTeam = ans[ans.size() - 1][0];
                int lastAwayTeam = ans[ans.size() - 1][1];
                int currHomeTeam = game[i][0];
                int currAwayTeam = game[i][1];
                if (lastHomeTeam != currHomeTeam and lastHomeTeam != currAwayTeam and lastAwayTeam != currHomeTeam and lastAwayTeam != currAwayTeam)
                {
                    ans.push_back(game[i]);
                    continue;
                }
                int j = 0;
                for (; j < ans.size(); j++)
                {
                    int nextHomeTeam = ans[j][0];
                    int nextAwayTeam = ans[j][1];
                    if (j == 0)
                    {
                        if (nextHomeTeam != currHomeTeam and nextHomeTeam != currAwayTeam and nextAwayTeam != currHomeTeam and nextAwayTeam != currAwayTeam)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    int prevHomeTeam = ans[j - 1][0];
                    int prevAwayTeam = ans[j - 1][1];
                    if (nextHomeTeam != currHomeTeam and nextHomeTeam != currAwayTeam and nextAwayTeam != currHomeTeam and nextAwayTeam != currAwayTeam and prevHomeTeam != currHomeTeam and prevHomeTeam != currAwayTeam and prevAwayTeam != currHomeTeam and prevAwayTeam != currAwayTeam)
                    {
                        break;
                    }
                }
                if (j == ans.size())
                {
                    temp.push_back(game[i]);
                }
                else
                {
                    ans.insert(ans.begin() + j, game[i]);
                }
            }
            game = temp;
        }
        return ans;
    }
};