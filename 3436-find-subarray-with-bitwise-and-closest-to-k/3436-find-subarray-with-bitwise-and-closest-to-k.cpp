class Solution {
public:
    // bit count 0's
    int calculateWindow(vector<int>& bit){
        int ans = 0;
        for(int i=0; i<32; i++){
            ans += (1<<i) * (bit[i] == 0);
        }
        return ans;
    }

    void addElement(vector<int>& bit, int el){
        for(int i=0; i<32; i++){
            if( !((el>>i) & 1) )
                bit[i]++;
        }
    }

    void subtractElement(vector<int>& bit, int el){
        for(int i=0; i<32; i++){
            if( !((el>>i) & 1))
                bit[i]--;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size(), minDiff = INT_MAX;

        vector<int> bit(32, 0);
        int i=0, j=0, rangeAnd=0;
        while(j<n){
            addElement(bit, nums[j]);
            rangeAnd = calculateWindow(bit);
            minDiff = min(minDiff, abs(rangeAnd-k));

            while(rangeAnd<k && i<j){
                subtractElement(bit, nums[i]);
                rangeAnd = calculateWindow(bit);
                minDiff = min(minDiff, abs(rangeAnd-k));
                i++;
            }

            j++;
            if(minDiff == 0) return 0;
        }

        return minDiff;
    }
};