/* 392. Is Subsequence */
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.equals("") && !t.equals("")) 
            return true;
        if (!s.equals("") && t.equals("")) 
            return false;
        
        LinkedList<Character> iso = new LinkedList<>();
        for (char c : s.toCharArray())
            iso.add(c);
        for (char c : t.toCharArray()) 
            if (iso.peek() != null && c == iso.peek())
                iso.pop();
        return iso.size() == 0;
    }
}

/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/
