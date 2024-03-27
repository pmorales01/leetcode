class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int idx = 0;
        int i = 0;
        bool make_column = true;
        
        vector<string> rows(numRows);
        
        while (idx < s.size()) {
            if (make_column) {
                rows[i] += s[idx];
                idx++;
                i++;
            } else {
                i--;
                if (i == 0) {
                    make_column = true;
                } else {
                    rows[i] += s[idx];
                    idx++;
                }
            }
            
            if (i == numRows) {
                make_column = false;
                i--;
            }
        }
        
        string output;
        
        for (string row : rows) {
            output += row;
        }
        
        return output;
    }
};
