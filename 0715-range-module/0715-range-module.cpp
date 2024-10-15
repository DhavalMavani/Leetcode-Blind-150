class SegmentTree{
    public:
    int l, r;
    bool state;
    SegmentTree *left=NULL, *right=NULL;
    SegmentTree(int l, int r, bool st) {
        this->l = l;
        this->r = r;
        this->state = st;
    }

    void update(int start, int end, bool state, SegmentTree* root) {
        if(root->l >= start && root->r <= end) {
            // complete overlap
            root->state = state;
            root->left = NULL;
            root->right = NULL;
            return;
        }
        else if(start >= root->r || end <= root->l) return; // no overlap

        // partial overlap
        int mid = root->l + (root->r - root->l) / 2;
        if(root->left == NULL) {
            root->left = new SegmentTree(root->l, mid, root->state);
            root->right = new SegmentTree(mid, root->r, root->state);
        }

        update(start, end, state, root->left);
        update(start, end, state, root->right);

        root->state = root->left->state && root->right->state;
    }

    bool query(SegmentTree *root, int start, int end) {

        if((root->l >= start && root->r <= end) || root->left == NULL) return root->state;

        int mid = root->l + (root->r - root->l) / 2;

        if(end <= mid) return query(root->left, start, end);
        else if(start >= mid) return query(root->right, start, end);
        else return query(root->left, start, end) && query(root->right, start, end);
    }

};

class RangeModule {
public:
    SegmentTree* root;

    RangeModule() {
        root = new SegmentTree(0, 1e9, false);
    }


    void addRange(int left, int right){
        root->update(left, right, true, root);
    }

    
    bool queryRange(int left, int right) {
        return root->query(root, left, right);
    }
    
    void removeRange(int left, int right) {
        root->update(left, right, false, root);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */