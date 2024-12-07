class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();

        vector<int> prevL(n,1e9);
        vector<int> prevR(n,1e9);


        int time=0;
        char prev='.';

        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                prevR[i]=0;
                prev='R';
                time=1;
            }else if(prev=='R' && dominoes[i]=='.'){
                prevR[i]=time;
                time++;
            }
            else if(dominoes[i]=='L') prev='L';
        }
        prev='.';
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                prevL[i]=0;
                prev='L';
                time=1;
            }else if(prev=='L' && dominoes[i]=='.'){
                prevL[i]=time;
                time++;
            }
            else if(dominoes[i]=='R') prev='R';
        }

        for(int i=0;i<n;i++){
            if(prevL[i]<prevR[i] ) dominoes[i]='L';
            else if(prevL[i]>prevR[i]) dominoes[i]='R';
        }

        return dominoes;        
    }
};