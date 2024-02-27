#include <iostream>






#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:

    std::string rankTeams(std::vector<std::string>& votes)
    {
      int numCandidates =  votes[0].size();
      std::string res(votes[0]);
      std::vector<std::vector<int>> rankings(numCandidates, std::vector<int>(26, 0));

      // First, populate the initial rankings
      for (auto& ballot : votes)
        for (int i = 0; i < numCandidates; ++i)
          rankings[i][ballot[i] - 'A']++;

      std::sort(res.begin(), res.end(), [&](char a, char b)
      {
        for (auto& ranking : rankings)
          // Sort lexographically if the candidates are the same.
          if (ranking[a - 'A'] != ranking[b - 'A'])
            return ranking[a - 'A'] > ranking[b - 'A'];
        // Otherwise, sort by the greatest number of first-choice votes.
        return a < b;
      });
      return res;
    }
};

  int main()
  {
    Solution s1;

    std::vector<std::string> votes = {"ABC","ACB","ABC","ACB","ACB"};
    auto res = s1.rankTeams(votes);
    std::cout << res << std::endl;

    return 0;
  }
