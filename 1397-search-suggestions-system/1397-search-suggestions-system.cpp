class Solution {
public:
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto start=products.begin();
        sort(start,products.end());
        vector<vector<string>>ans;
        vector<string>temp;
        string curr;
        for(auto c:searchWord){
            curr+=c;
            temp.clear();
            start=lower_bound(start,products.end(),curr);
            for(int i=0;i<3 && start+i!=products.end();i++){
                string s=*(start+i);
                if(s.find(curr))break;
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};