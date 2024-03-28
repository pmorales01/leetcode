class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            // X has a negative sign 
            return false;
        }

        double reverse = 0;

        int num = x;

        while (num > 0) {
            // mod number by 10 to get right most place
            int digit = num % 10;

            // add digit to left most place
            reverse = reverse * 10 + digit;
            
            // divide number by 10 to get the digit one place to the left
            num /= 10;
        }

        return reverse == x;
    }
};
