#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> tree;

    // build the segment tree
    void build(vector<int>& baskets , int node , int l , int r){
        if (l == r) {
            tree[node] = baskets[l];
            return;
        }

        int mid = (l + r) / 2;
        // build left side 
        build(baskets, node * 2 , l , mid);

        // build right side
        build(baskets , node * 2 + 1 , mid + 1 , r);

        tree[node] = max(tree[node * 2] , tree[node * 2 + 1]); // find the maximum between the left child and the right child
    }

    // find the left most basket with capacity >= fruit
    int find(int node , int l , int r , int x){
        if (tree[node] < x) return -1;

        if (l == r) return l;

        int mid = (l + r) / 2;

        if (tree[node * 2] >= x) {
            return find(node * 2 , l , mid , x);
        }

        return find(node * 2 + 1 , mid + 1 , r , x);
    }

    // mark baskets as used
    void update (int node , int l , int r , int p) {
        if (l == r) {
            tree[node] = -1;
            return;
        }

        int mid = (l + r) / 2;

        if (p <= mid) update(node * 2 , l , mid , p);
        else update(node * 2 + 1 , mid + 1 , r , p);

        tree[node] = max(tree[node * 2] , tree[node * 2 + 1]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        tree.resize(4 * n);

        build(baskets , 1 , 0 , n - 1);

        int res = 0;

        for (int fruit : fruits) {
            int pos = find(1 , 0 , n - 1 , fruit);

            if (pos == -1){
                res++;
            } else {
                update(1 , 0 , n - 1 , pos);
            }
        }

        return res;
    }
};