class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(),ans=0;
        unordered_set<int> isNumPresent;

        for(auto &num: arr) isNumPresent.emplace(num);

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int num1=arr[i], num2=arr[j];

                int len=2;
                while( isNumPresent.count(num1+num2) ){
                    int total=num1+num2;
                    num1=num2;
                    num2=total;
                    len++;
                }

                ans=max(ans,len);
            }
        }

        if(ans==2) return 0;
        return ans;

    }
};

//  arr = [1,3,7,11,12,14,18]

//  1,3 check 4 x
//  1,7 check 8 x
//  1,11 check 12 -> 11,12 -> check 23 x
//  1,12
//  1,14
//  1,18

//  3,7 check 10
 
//  3,11 check 14 ->  11,14 check 25  -> 14, 25


// arr = [1,3,7,11,12,14,18]