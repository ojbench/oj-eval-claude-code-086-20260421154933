#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> leftc(n + 1), rightc(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        leftc[i] = a;
        rightc[i] = b;
    }
    int t;
    cin >> t;
    vector<int> ks(t);
    for (int i = 0; i < t; ++i) cin >> ks[i];

    // Compute depths starting from root=1 (depth 1)
    vector<int> depth(n + 1, 0);
    queue<int> q;
    depth[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int l = leftc[u];
        int r = rightc[u];
        if (l != -1) { depth[l] = depth[u] + 1; q.push(l); }
        if (r != -1) { depth[r] = depth[u] + 1; q.push(r); }
    }

    auto inorder = [&](int root) {
        vector<int> res;
        res.reserve(n);
        // iterative inorder
        vector<int> st;
        int cur = root;
        while (cur != -1 || !st.empty()) {
            while (cur != -1) {
                st.push_back(cur);
                cur = leftc[cur];
            }
            int node = st.back(); st.pop_back();
            res.push_back(node);
            cur = rightc[node];
        }
        return res;
    };

    for (int k : ks) {
        for (int i = 1; i <= n; ++i) {
            if (depth[i] != 0 && depth[i] % k == 0) {
                swap(leftc[i], rightc[i]);
            }
        }
        auto seq = inorder(1);
        for (size_t i = 0; i < seq.size(); ++i) {
            cout << seq[i];
            if (i + 1 <= seq.size()) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
