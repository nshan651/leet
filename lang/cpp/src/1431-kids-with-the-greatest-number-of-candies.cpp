#include <iostream>






#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
    std::vector<bool> result;
    // Max element returns an iter from [foundPos, endPos]
    // Dereference this to get the actual max value
    int mostCandies = *std::max_element(candies.begin(), candies.end());

    std::transform(candies.begin(), candies.end(), std::back_inserter(result),
                   [&](int i) { return (i + extraCandies) >= mostCandies; });

    return result;
  }

};
int main()
{
  Solution s1;

  // [2,3,5,1,3]
  // 3
  std::vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;

  std::vector<bool> res = s1.kidsWithCandies(candies, extraCandies);

  for (bool b : res)
    std::cout << b << std::endl;
}
