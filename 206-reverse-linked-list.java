/* 206. Reverse Linked List */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    /* Iterative solution */ 
    public ListNode reverseList(ListNode head) {
        ListNode prev = null, curr = head, next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }

    /* Recursive solution */
    public ListNode recursiveReverse(ListNode head) {
        ListNode curr = head;
        return helper(null, curr, null);
    }
    
    private ListNode helper(ListNode prev, ListNode curr, ListNode next) {
        if (curr == null) 
            return prev;
        
        next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
        
        return helper(prev, curr, next);
    }
    
    private void debug(ListNode n) {
        while (n != null) {
            System.out.println(n.val);
            n = n.next;
        }
    }
}

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []
*/

/* Bonus recursive implementation */
class Solution {
