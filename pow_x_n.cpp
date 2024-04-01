class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        
        double power = 1;

        int abs_n = abs(n);

        while (abs_n > 0) {
            if (abs_n % 2) {
                power *= x;
            }
            x *= x;
            abs_n /= 2;
        }

        return n > 0 ? power : 1 / power;
    }
};
