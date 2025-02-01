class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> romanNum={ {"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10}, {"XL",40},{"L",50},
        {"XC",90},{"C",100},{"CD",400},{"D", 500} ,{"CM",900}, {"M",1000}  };

        int i=romanNum.size()-1;
        string ans="";
        while(num){
            if(num/romanNum[i].second!=0){
                for(int j=0;j<num/romanNum[i].second;j++) ans+=romanNum[i].first;
                num=num%romanNum[i].second;
            }
            i--;
        }

        return ans;
    }
};




// xxx ix

// ptr=right;
// while(ptr>=0 ){

// }

// M CM  XC   IV 
// 4+90+ 900+1000


// 99
// XCIX


// 4

// v
// 6

// xx IV
// 24


// III
// 3

// II
// 2

// 10
// X

// I             1
// IV            4
// V             5
// IX            9
// X             10
// XL            40
// L             50
// XC            90
// C             100
// CD            400
// D             500
// CM            900
// M             1000
