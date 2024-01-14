#include <array>
#include <iostream>
#include <memory>
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode()
  {
    while (!next)
    {
      ListNode* tmp = next;
      next = next->next;
      delete tmp;
    }
  }
};

ListNode* createListFromArray(std::array<int, 5> nums)
{
  ListNode* head(nullptr);
  ListNode* tmp;

  for (const auto i : nums)
  {
    tmp = new ListNode(i);
    tmp->next = head;
    head = tmp;
  }
  return head;
}

void printList(ListNode* head) {
  while (head != nullptr)
  {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

// int main()
// {
//   std::array<int, 5> nums = {1, 2, 3, 4, 5};
//   ListNode* head = createListFromArray(nums);
//   printList(head);
// }
