class SegmentTree{
public:
    vector<int> segTree;

    SegmentTree(vector<int>& nums){
        segTree.resize(4*nums.size(),0);
        buildTree(0,0,nums.size()-1,nums);
    }

    void buildTree(int ind, int l,int r,vector<int> &nums){
        if(l==r){
            segTree[ind]=nums[l];
            return;
        }
        
        int mid=(l+r)/2;
        buildTree(2*ind+1,l,mid, nums );
        buildTree(2*ind+2,mid+1,r, nums );

        segTree[ind]=segTree[ind*2+1]+segTree[ind*2+2];
    }

    void updateTree(int &index, int &val, int ind,int l, int r){
        if(l==r){
            segTree[ind]=val;
            return;
        }
        int mid=(l+r)/2;

        if(index<=mid) updateTree(index,val,ind*2+1,l,mid );
        else updateTree(index,val,ind*2+2,mid+1,r );

        segTree[ind]=segTree[ind*2+1]+segTree[ind*2+2];
    }

    int sumRange(int start, int end,int ind,int l,int r){
        if(l>=start && end>=r) return segTree[ind]; // complete overlap 
        else if(l>end || start>r) return 0; // no overlap 

        // partial overlap
        int mid=(l+r)/2;
        int leftSide=sumRange(start,end,ind*2+1,l,mid);
        int rightSide=sumRange(start,end,ind*2+2,mid+1,r);
        
        return leftSide+rightSide;
    }
};

class NumArray {
public:
    int n;
    SegmentTree* st;
    NumArray(vector<int>& nums) {
        st=new SegmentTree(nums);
        n=nums.size();
    }
    
    void update(int index, int val) {
        st->updateTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return st->sumRange(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */