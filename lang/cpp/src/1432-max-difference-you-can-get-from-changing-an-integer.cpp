#include <iostream>






#include <limits.h>

class Solution {
public:
  int maxDiff(int num)
  {
    int a = INT_MIN, b = INT_MAX;
    std::string s = std::to_string(num);

    for (char x = '0'; x <= '9'; x++)
    {
      for (char y = '0'; y <= '9'; y++)
      {
        std::string newNum = s;
        for (char& c : newNum)
          if (c == x)
            c = y;

        // checking for leading zero
        if (newNum[0] == '0')
          continue;

        int newNumInt = stoi(newNum);
        a = std::max(a, newNumInt);
        b = std::min(b, newNumInt);
      }
    }

    return a - b;
  }
};

int main()
{
  Solution s1;

  int num = 555;
  int res = s1.maxDiff(num);

  std::cout << res << std::endl;

  return 0;
}
