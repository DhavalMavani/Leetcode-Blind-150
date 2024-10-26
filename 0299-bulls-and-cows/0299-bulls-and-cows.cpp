class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        vector<int> secretCount(10,0);
        vector<int> guessCount(10,0);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) b++;
            else{
                secretCount[secret[i]-'0']++;
                guessCount[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++) a+=min(secretCount[i],guessCount[i]);
        
        return to_string(b)+'A'+ to_string(a)+'B';
    }
};