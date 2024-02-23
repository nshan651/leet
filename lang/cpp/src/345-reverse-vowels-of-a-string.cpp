#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Solution
{
public:

  std::string reverseVowels(std::string s)
  {
    auto isVowel = [](char c)
    { return c == 'a' || c == 'e' || c == 'i' || c == 'o'
	|| c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    };

    int left = 0, right = s.size() - 1;

    while (left < right)
    {
      if (!isVowel(s[left]))
	left++;
      if (!isVowel(s[right]))
	right--;
      if (isVowel(s[left]) && isVowel(s[right]))
	std::swap(s[left++], s[right--]);
    }

    return s;
  }
};

int main()
{
  Solution s1;

  std::string v = "hello";
  std::string res = s1.reverseVowels(v);

  std::cout << res << std::endl;

  return 0;
}
