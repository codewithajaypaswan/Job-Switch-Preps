class Solution {
public:
    string belowTen[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    string belowTwenty[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    string belowHundred[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return trim(solve(num));
    }
    
    string solve(int num) {
        if(num < 10) return belowTen[num];
        else if(num < 20) return belowTwenty[num - 10];
        else if(num < 100) return belowHundred[num / 10] + (num % 10 != 0 ? " " + solve(num % 10) : "");
        else if(num < 1000) return solve(num / 100) + " Hundred" + (num % 100 != 0 ? " " + solve(num % 100) : "");
        else if(num < 1000000) return solve(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + solve(num % 1000) : "");
        else if(num < 1000000000) return solve(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + solve(num % 1000000) : "");
        return solve(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + solve(num % 1000000000) : "");
    }
    
    string trim(const string& str) {
        int start = 0, end = str.size() - 1;
        while(start < str.size() && isspace(str[start])) ++start;
        while(end >= 0 && isspace(str[end])) --end;
        return str.substr(start, end - start + 1);
    }
};
