class PST{
    struct node{
        int left = 0, right = 0;
        LL a = 0, b = 0;
    };
    node *tree;
    int N, LG, time = 0, I = 0;
 
    LL merge(LL a, LL b){ 
        return a + b;
    }
    node create(int l, int r){
        return {l, r, merge(tree[l].a, tree[r].a), merge(tree[l].b, tree[r].b)};
    }
    int build(int le, int ri){
        int id = ++time;
        if(le == ri) return tree[id] = node(), id;
        int m = (le + ri) / 2;
        return tree[id] = create(build(le, m), build(m + 1, ri)), id;
    }
    int update(int id, int le, int ri, int pos, int a, int b){
        int nid = ++time;
        if(le == ri) return tree[nid] = {0, 0, tree[id].a + a, tree[id].b + b}, nid; // change here
        int m = (le + ri) / 2;
        if(pos <= m){
            tree[nid] = create(update(tree[id].left, le, m, pos, a, b), tree[id].right);
        }else{
            tree[nid] = create(tree[id].left, update(tree[id].right, m + 1, ri, pos, a, b));
        }
        return nid;
    }
    PLL query(int id, int le, int ri, int l, int r){
        if(le > r || l > ri) return {0, 0};
        if(le >= l && ri <= r) return {tree[id].a, tree[id].b};
        int m = (le + ri) >> 1;
        
        PLL left = query(tree[id].left, le, m, l, r), right = query(tree[id].right, m + 1, ri, l, r);
        return {left.first + right.first, left.second + right.second};
    }
    
public:
    PST(int N, int U){
        this->N = N;
        LG = 32 - __builtin_clz(N) + 1;
        tree = new node[(N + U) * LG];
        build(0, N - 1); 
    }
    int update(int id, int pos, int a, int b){
        return update(id, 0, N - 1, pos, a, b);
    }
    PLL query(int id, int l, int r){
        return query(id, 0, N - 1, l, r);
    }
    ~PST(){
        delete[] tree;
    }
};