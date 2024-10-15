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
};

class RangeModule {
public:
    SegmentTree* root;

    RangeModule() {
        root = new SegmentTree(0, 1e9, false);
    }

    void update(int l, int r, bool state, SegmentTree* root) {
        if(root->l >= l && root->r <= r) {
            root->state = state;
            root->left = NULL;
            root->right = NULL;
            return;
        }
        if(l >= root->r || r <= root->l) return;

        int mid = root->l + (root->r - root->l) / 2;
        if(root->left == NULL) {
            root->left = new SegmentTree(root->l, mid, root->state);
            root->right = new SegmentTree(mid, root->r, root->state);
        }

        update(l, r, state, root->left);
        update(l, r, state, root->right);

        root->state = root->left->state && root->right->state;
    }

    void addRange(int left, int right){
        update(left, right, true, root);
    }

    bool q(SegmentTree *root, int l, int r) {

        if((root->l >= l && root->r <= r) || root->left == NULL) return root->state;

        int mid = root->l + (root->r - root->l) / 2;

        if(r <= mid) return q(root->left, l, r);
        else if(l >= mid) return q(root->right, l, r);
        else return q(root->left, l, r) && q(root->right, l, r);
    }
    
    bool queryRange(int left, int right) {
        return q(root, left, right);
    }
    
    void removeRange(int left, int right) {
        update(left, right, false, root);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */