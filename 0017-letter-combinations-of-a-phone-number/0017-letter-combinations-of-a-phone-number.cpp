class Solution {
public:
    vector<string> keyPad={"","","abc","def","ghi","jkl", "mno","pqrs","tuv","wxyz" };
    
    void helper(string digits, int index,vector<string> &ans,string res){
        if(index==digits.size()){
            ans.emplace_back(res);
            return;
        }

        for(auto i: keyPad[ digits[index] -'0' ]){
            helper(digits,index+1,ans,res+i);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        helper(digits,0,ans,"");
        return ans;
    }
};