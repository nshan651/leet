/* 35. Search Insert Position */
class Solution {
    // Binary Search
    public int searchInsert(int[] nums, int target) {
        int answer = bsearch(nums, target, 0, nums.length-1);
        return answer;
    }
    
    public int bsearch(int[] nums, int target, int left, int right) {
        if (left > right) return left;
        
        int mid = (left+right)/2;
        
        // Found solution
        if (nums[mid] == target) return mid; 
        // Divide and conquer
        if (nums[mid] > target) return bsearch(nums, target, left, mid-1); 
        if (nums[mid] < target) return bsearch(nums, target, mid+1, right); 
        // Otherwise, return -1
        return -1;
    }
}

/* 35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104
*/
