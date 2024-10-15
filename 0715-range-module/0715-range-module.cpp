class SegmentTree {
public:
    int l, r;
    bool state;
    SegmentTree *left = nullptr, *right = nullptr;

    SegmentTree(int l, int r, bool state) : l(l), r(r), state(state) {}

    void createChildren() {
        if (!left) {
            int mid = l + (r - l) / 2;
            left = new SegmentTree(l, mid, state);
            right = new SegmentTree(mid, r, state);
        }
    }

    void update(int start, int end, bool newState) {
        // If the current node's range is completely within the [start, end] range
        if (start <= l && r <= end) {
            state = newState;
            delete left;  // Clean up child nodes
            delete right;
            left = right = nullptr;
            return;
        }
        // No overlap
        if (end <= l || start >= r) return;

        // Partial overlap: split the range into children
        createChildren();

        // Recursively update the children
        left->update(start, end, newState);
        right->update(start, end, newState);

        // Update current node's state based on the children's states
        state = left->state && right->state;
    }

    bool query(int start, int end) {
        // If the current node's range is fully within the query range
        if ((start <= l && r <= end) || !left) return state;

        int mid = l + (r - l) / 2;
        // Check query for partial overlaps
        if (end <= mid) return left->query(start, end);
        else if (start >= mid) return right->query(start, end);
        else return left->query(start, end) && right->query(start, end);
    }
};

class RangeModule {
private:
    SegmentTree* root;

public:
    RangeModule() {
        root = new SegmentTree(0, 1e9, false);  // Full range [0, 10^9) initially inactive
    }

    void addRange(int left, int right) {
        root->update(left, right, true);
    }

    bool queryRange(int left, int right) {
        return root->query(left, right);
    }

    void removeRange(int left, int right) {
        root->update(left, right, false);
    }
};
