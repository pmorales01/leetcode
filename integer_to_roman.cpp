class Solution {
public:
    string intToRoman(int num) {
        string roman;
    
        int power = floor(log10(num));
        
        while (num > 0) {
            // get the left most digit
            int digit = num / int(pow(10, power));
            
            switch (power) {
                case 3: // 1000s
                    roman += string(digit, 'M');
                    break;
                case 2: // 100s
                    if (digit < 4) {
                        roman += string(digit, 'C');
                    } else if (digit == 4) {
                        roman += "CD";
                    } else if (digit == 5) {
                        roman += "D";
                    } else if (digit > 5 && digit < 9) {
                        roman = roman + "D" + string(digit - 5, 'C');
                    } else {
                        roman += "CM";
                    }
                    break;
                case 1: // 10s
                    if (digit < 4) {
                        roman += string(digit, 'X');
                    } else if (digit == 4) {
                        roman += "XL";
                    } else if (digit == 5) {
                        roman += "L";
                    } else if (digit > 5 && digit < 9) {
                        roman = roman + "L" + string(digit - 5, 'X');
                    } else {
                        roman += "XC";
                    }
                    break;
                case 0: 
                    if (digit < 4) {
                        roman += string(digit, 'I');
                    } else if (digit == 4) {
                        roman += "IV";
                    } else if (digit == 5) {
                        roman += "V";
                    } else if (digit > 5 && digit < 9) {
                        roman = roman + "V" + string(digit - 5, 'I');
                    } else {
                        roman += "IX";
                    }
                    break;
            }
            
            // move to the next right digit
            num = num % int(pow(10, power));
            
            // 10 ^ (n - 1)
            power--;
        }
        
        return roman;
    }
};
