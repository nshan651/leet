#include <iostream>





#include <vector>
#include <map>
// using namespace std;
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::map<int, int> prevStore;

      int i = 0;
      for (auto n : nums)
      {
        int diff = target - n;
        if (prevStore.contains(diff))
          return {prevStore[diff], i};
        prevStore[n] = i;
        i++;
      }
      return {};
    }
};

int main()
{
  // [2,15,11,7,22,25], target = 9
  Solution s1;
  std::vector<int> nums = {2,15,11,7,22,25};
  int target = 9;
  auto res = s1.twoSum(nums, target);

  for (auto i : res)
    std::cout << i << "\n";

}
