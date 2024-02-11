#include <iostream>






#include <vector>
#include <algorithm>

class Solution {
public:
  string longestPalindrome(string s)
  {
    // Midpoint ceiling
    int mid = (s.size() + 2 - 1) / 2;

    std::cout << mid;

    // for (int i = 0, j = s.size()-1; i < s.size() && j >= 0; i++, j--)
    // {

    // }
  }
};

int main()
{
  Solution s1;

  std::string pali = "abiba";
  std::string longest = s1.longestPalindrome(pali);

  return 0;
}
