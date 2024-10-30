class Solution {
public:
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        string curr;

        for(auto &c:searchWord){
            curr+=c;
            vector<string>temp;
            auto start=lower_bound(products.begin(),products.end(),curr);

            for(int i=0;i<3 && start+i!=products.end();i++){
                string s=*(start+i);
                if(s.find(curr)) break;
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};