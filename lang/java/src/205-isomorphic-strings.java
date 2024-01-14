/* 205. Isomorphic Strings */
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> iso = new HashMap<>();
        Set<Character> assigned = new HashSet<>();
        
        for (int i = 0; i< s.length(); i++) {
            if (iso.containsKey(s.charAt(i)) && iso.get(s.charAt(i)) != t.charAt(i)) 
                return false;
            if (!iso.containsKey(s.charAt(i)) && assigned.contains(t.charAt(i))) 
                return false;
            iso.put(s.charAt(i), t.charAt(i));
            assigned.add(t.charAt(i));
        }
        return true;
    }
}

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true
*/
