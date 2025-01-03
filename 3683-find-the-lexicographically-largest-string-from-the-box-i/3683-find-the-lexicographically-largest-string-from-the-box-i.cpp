class Solution {
public:
    string comp(string &a, string b){
        int n1=a.size(),n2=b.size(), n=min(n1,n2), i=0;

        while(i<n && a[i]==b[i]) i++;

        if(i==n1 || i==n2){
            if(n1>n2)return a;
            else return a=b;
        }
        if((a[i]-'a')>(b[i]-'a')) return a;

        return a=b;
    }
    string answerString(string word, int numFriends) {
        int n=word.size(),windowSize=n-numFriends+1,ind=n-1;
        if(numFriends==1) return word;
        string ans="";

        while(ind>=n-windowSize){
            comp(ans,word.substr(ind));
            ind--;
        }

        while(ind>=0){
            comp(ans,word.substr(ind,windowSize));
            ind--;
        }

        return ans;
    }
};