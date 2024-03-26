class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::map<int,int> map;

            for (int i=0; i<nums.size(); ++i) {
                map.insert(std::pair<int,int>(nums[i], i));
            }

            for (int i=0; i<nums.size(); ++i) {
                int diff = target - nums[i];

                std::map<int,int>::iterator it = map.find(diff);

                if (it != map.end() && i != map[diff]) {
                    return vector<int>({i, map[diff]});
                }
            }

            return vector<int>();
        }
    };
