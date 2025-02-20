class SegmentTree {
    vector<long long> tree, lazy;
    int n;

    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node initialization
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1]; // Combine
        }
    }

    void apply(int node, int start, int end, long long value) {
        tree[node] += value * (end - start + 1); // Apply the update
        if (start != end) { // Mark children as lazy
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) { // Propagate the lazy value
            apply(node, start, end, lazy[node]);
            lazy[node] = 0; // Clear the lazy value
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long value) {
        push(node, start, end);
        if (start > r || end < l) return; // No overlap
        if (start >= l && end <= r) { // Total overlap
            apply(node, start, end, value);
            return;
        }
        // Partial overlap
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // Recalculate
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (start > r || end < l) return 0; // No overlap
        if (start >= l && end <= r) return tree[node]; // Total overlap
        // Partial overlap
        int mid = (start + end) / 2;
        return queryRange(node * 2, start, mid, l, r) +
               queryRange(node * 2 + 1, mid + 1, end, l, r);
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void updateRange(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    long long queryRange(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};