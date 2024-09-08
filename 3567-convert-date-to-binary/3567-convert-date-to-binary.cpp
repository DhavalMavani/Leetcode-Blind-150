class Solution {
public:

    string intToBinary(int n) {
        if (n == 0) return "0";
        string binary = "";
        
        while (n) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        
        return binary;
    }

    string convertDateToBinary(string date) {
        return intToBinary(stoi(date.substr(0,4))) +"-"+ intToBinary(stoi(date.substr(5,2))) + "-" + intToBinary(stoi(date.substr(8,2)));

    }
};