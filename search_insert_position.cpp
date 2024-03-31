class Solution {
public:
    int searchInsertHelper(vector<int>& nums, int start, int end, int target) {
        if (end >= start) {
            int mid = (start + end) / 2;       
            
            if (nums[mid] == target) {
                return mid;
            } 
            
            if (nums[mid] < target) { /* go right */
                return searchInsertHelper(nums, mid + 1, end, target);
            }
            
            /* nums[mid] > target, go left */
            return searchInsertHelper(nums, start, mid - 1, target);
        }
        
        return start;
    }

    int searchInsert(vector<int>& nums, int target) {
        return searchInsertHelper(nums, 0, nums.size() - 1, target);
    }

};
