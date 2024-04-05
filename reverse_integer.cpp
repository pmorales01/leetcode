class Solution {
public:
    int reverse(int x) {
        long long int reverse = 0;

        int original = x;

        while (x != 0) {
            // get the right most digit
            int digit = x % 10;

            // set the current digit to be the left most
            reverse = reverse * 10 + digit;

            // get the next digit
            x /= 10;
        }

        // check if the reverse int exceeds the 32-bit INT range
        return (reverse > INT_MAX || reverse < INT_MIN) ? 0 : reverse;
    }
};
