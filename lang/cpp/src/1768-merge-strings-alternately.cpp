#include <iostream>


#include <string>

class Solution {
public:
  std::string mergeAlternately(std::string word1, std::string word2) {
    std::string res("");
    int i = 0;

    while (i < word1.size() && i < word2.size())
    {
      res.push_back(word1[i]);
      res.push_back(word2[i]);
      i++;
    }

    // Merge remaining chars in word1
    while (i < word1.size())
    {
      res.push_back(word1[i]);
      i++;
    }

    // Merge remaining chars in word2
    while (i < word2.size())
    {
      res.push_back(word2[i]);
      i++;
    }

    return res;
  }
};

int main()
{
  Solution s1;

  // Input: word1 = "abc", word2 = "pqr"
  // Output: "apbqcr"

  std::string word1("abcdef");
  std::string word2("pqr");

  std::string res = s1.mergeAlternately(word1, word2);
  std::cout << res << std::endl;
}
