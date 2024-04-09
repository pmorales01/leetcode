class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // get the first string
        string first_str = strs[0];
        
        string prefix = "";

        int i = 0;
        
        // for each character of the first string...
        while (i < first_str.length()) {
            // ... go through the rest of the strings
            for (int j=1; j<strs.size(); j++) {
                // if current char is not the same, longest prefix reached
                if (first_str[i] != strs[j][i]) {
                    return prefix;
                }
            }
          
            // all ith characters matched, add char to prefix string
            prefix += first_str[i];

            // compare next character
            i++;
        }

        return prefix;
    }
};
