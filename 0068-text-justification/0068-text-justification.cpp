class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n=words.size(),ind=0;
        vector<string> ans;

        while(ind<n){
            int r=ind, remainingLen=maxWidth;

            while(r<n && (remainingLen>= words[r].size()+ r-ind) ){
                remainingLen-=words[r].size();
                r++;
            }

            int numOfWords=r-ind;
            string s;
            if(r==n || numOfWords==1){
                for(int j=ind;j<r;j++) s+=words[j]+' ';
                s.pop_back();
                s.append(remainingLen-(numOfWords-1),' ');
            }
            else {
                int spaceSize=remainingLen/(numOfWords-1),extraSpace=remainingLen%(numOfWords-1);
                for(int j=ind;j<r-1;j++){
                    s+=words[j];
                    s.append(spaceSize,' ');
                    if(extraSpace){
                        s+=' ';
                        extraSpace--;
                    }
                }
                s+=words[r-1];
            }
            ans.emplace_back(s);
            ind=r;
        }
        return ans;
    }
};