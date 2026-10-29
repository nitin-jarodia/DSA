class Solution {
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    vector<int> pref;
    string s;
    int timer, LOG, n;

    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int root) {
        vector<int> parent(n, -1);
        vector<pair<int, bool>> st;
        st.push_back({root, false});

        while (!st.empty()) {
            auto [u, exit] = st.back();
            st.pop_back();

            if (exit) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;
            pref[u] = (parent[u] == -1 ? 0 : pref[parent[u]])
                      ^ mask(s[u]);

            up[u][0] = (parent[u] == -1 ? u : parent[u]);

            for (int j = 1; j < LOG; j++)
                up[u][j] = up[up[u][j - 1]][j - 1];

            st.push_back({u, true});

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back({v, false});
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[u][j];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        pref.assign(n, 0);
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0);

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);

                if (delta != 0) {
                    add(tin[u], delta);
                    add(tout[u] + 1, delta);
                    s[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);

                int pu = pref[u] ^ get(tin[u]);
                int pv = pref[v] ^ get(tin[v]);

                int pathMask = pu ^ pv ^ mask(s[w]);

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};