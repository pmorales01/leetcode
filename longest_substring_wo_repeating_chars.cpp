class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        
        // left = beginning of sliding window, right = end
        int max=0, left=0, right=0;

        while (right < s.length()) {
            unordered_map<char,int>::iterator it = hash.find(s[right]);

            if (it == hash.end()) { /* character not found */
                // add (char,index) to hash map
                hash.insert(pair<char,int>(s[right], 1));
                
                // left - right = substring length
                max = std::max(right - left + 1, max);

                // move to next char
                right++;
            } else { /* character repeated */                
                // delete repeated character from map
                hash.erase(s[left]);

                left++;
            }
        }
        return max;
    }
};
