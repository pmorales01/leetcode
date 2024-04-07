class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        map<char,int> digits;

        // map chars to digits 
        for (char c = '0'; c <= '9'; ++c) {
            digits[c] = c - '0';
        }

        /* ignore whitespaces */
        while (true) {
            if (s[i] != ' ') {
                break;
            }
            i++;
        }

        int is_negative = false;

        // determine if int is negative/positive
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') is_negative = true;
            i++;
        }

        long long int integer = 0;
        
        while(isdigit(s[i]) != 0 && i < s.length()) {
            if (is_negative) {
                integer = integer * 10 - digits[s[i]];
            } else {
                integer = integer * 10 + digits[s[i]];
            }

            // Handle overflow
            if (integer > INT_MAX) {
                return INT_MAX;
            } else if (integer < INT_MIN) {
                return is_negative ? INT_MIN : INT_MAX;
            }

            i++;
        }

        return integer;
    }
};
