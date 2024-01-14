#include <iostream>






#include <iostream>
#include "ListNode.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  /** Iterative */
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (head != nullptr)
      {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
    return prev;
  }
};

int main()
{
  Solution s1;
  std::array<int, 5> nums = {1, 2, 3, 4, 69};
  ListNode* head = createListFromArray(nums);
  printList(head);

  ListNode* r1 = s1.reverseList(head);
  printList(r1);

  return 0;
}

#include <iostream>






int main() {
class Solution {
public:
    /** Recursive */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        function<ListNode*(ListNode*, ListNode*)>
        reverseList =
        [&reverseList](ListNode* prev, ListNode* head) -> ListNode*
        {
            if (!head) return prev;
            ListNode* next = head->next;
            head->next = prev;
            return reverseList(head, next);
        };
        return reverseList(prev, head);
    }
};
return 0;
}
