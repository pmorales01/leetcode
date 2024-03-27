/*
Time complexity: O(N)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // total_size = n + m
        int total_size = nums1.size() + nums2.size();
        
        int intValue = std::numeric_limits<int>::max();

        int half = ((nums1.size() + nums2.size()) / 2) + 1;

        vector<double> merged;

        vector<int>::iterator it_1 = nums1.begin();
        vector<int>::iterator it_2 = nums2.begin();

        while (merged.size() != half) {
            if (it_1 != nums1.end() && it_2 == nums2.end()) {
                merged.push_back(*it_1);
                it_1++;
            } else if (it_2 != nums2.end() && it_1 == nums1.end()) {
                merged.push_back(*it_2);
                it_2++;
            } else if (it_1 != nums1.end() && *it_1 <= *it_2) {
                merged.push_back(*it_1);
                it_1++;
            } else if (it_2 != nums2.end() && *it_2 <= *it_1) {
                merged.push_back(*it_2);
                it_2++;
            }
        }

        if (total_size % 2) {
            return merged.back();
        } else {
            double last = merged.back();

            double penultimate = merged[half-2];
          
            return double((last + penultimate) / 2);
        }

        return 0;
    }
};
