class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                // swap with last element of nums
                nums[i] = nums[nums.size() - 1];

                // pop the last element
                nums.pop_back();
            } else {
                i++;
            }
        }
        return nums.size();
    }
};


/* alternate example
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // return 0, if size == 0
        if (!nums.size()) {
            return 0;
        }

        int i = 0;

        for (int x : nums) {
            if(x!=val) {
                // assign the current number to the ith index, then increment
                nums[i++]=x;
            }
        }
        
        // return k (first k elements)
        return i;
    }
};
*/
