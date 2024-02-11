#include <iostream>






#include <string>

// Recursive
class Solution {
public:

  std::string gcdOfStrings(std::string str1, std::string str2)
  {
    // Ensure that str1 is always greater than  str2.
    if (str1.size() < str2.size())
      return gcdOfStrings(str2, str1);

    // Cut off common prefix and recurr.
    if (str1.find(str2)  == 0 && str2 != "")
      return gcdOfStrings(str1.substr(str2.size()), str2);

    // GCD string is found
    if (str2.empty())
      return str1;

    // GCD not found
    return "";
  }

};

// Iterative
class Solution2 {
public:

  std::string gcdOfStrings(std::string str1, std::string str2)
  {
    std::string prefix(str1), suffix(str2);
    while (true)
    {
      // Use the larger of prefix and suffix
      if (prefix.size() < suffix.size())
        prefix.swap(suffix);

      // If the first occurence of suffix in prefix not at index zero, then there cannot be a GCD.
      else if (prefix.find(suffix))
        return "";

      // Empty suffix means we've finished searching prefix substr, so prefix is GCD
      else if (suffix.empty())
        return prefix;

      // Search f(g(x))
      else
        prefix = prefix.substr(suffix.size());
    }

    // GCD not found
    return "";
  }

};

int main()
{
  Solution s1;
  Solution s2;

  // Input: str1 = "ABCABC", str2 = "ABC"
  // Output: "ABC"
  std::string word1("ABCABC");
  std::string word2("ABC");

  std::string res = s2.gcdOfStrings(word1, word2);
  std::cout << res << std::endl;
}
