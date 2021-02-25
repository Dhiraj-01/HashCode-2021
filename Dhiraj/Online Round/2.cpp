#include "bits/stdc++.h"
using namespace std;

#define int int64_t

typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l = 0, int r = INT_MAX) {return uniform_int_distribution<int>(l, r)(rng);}

bool in_range(int x, int l, int r) {return l <= x && x <= r;}
template<typename H, typename ...T>void inp(H &head) {cin >> head;}
template<typename H, typename ...T>void inp(H &head, T &...tail) {cin >> head;inp(tail...);}
template<typename T>inline istream &operator >>(istream &in, vector<T> &a) {for(T &x : a)in >> x; return in;}
template<typename T, typename U>inline istream &operator >>(istream &in, pair<T, U> &a) {in >> a.first >> a.second; return in;}

// Multi-Dimension Vector
// Usage: vec<n, data-type> dp(dimention-1, dimention-2, ..., dimention-n, default = data-type())
template<int D, typename T> struct vec : public vector<vec<D - 1, T>>
{
    static_assert(D >= 1, "Vector dimensions must be greater than zero !!");
    template<typename... Args>
    vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)){}
};

template<typename T> struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val){}};

const int inf = 1e15;
const bool testcases = false;

void preprocess();
void solve(int tc);
int32_t main(int32_t argc, char **argv)
{
    preprocess();
    int TC = 1;
    if(testcases)
        cin >> TC;

    for(int tc = 1; tc <= TC; ++tc) {
        solve(tc);
    }
    exit(0);
}

void preprocess()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
        // for debug in error.txt
        freopen("error.txt", "w", stderr);
    #endif
}

int d, n, m, c, f;
map<string, int> etoi;
map<int, string> itoe;
map<int, int> edgeBegin;
map<int, map<int, pii>> g;

struct car {
    int p;
    vector<int> eid;

    friend istream& operator >>(istream &in, car &var) {
        int x;
        in >> x;
        var.p = x;
        var.eid.resize(x);
        string s;
        for(int i = 0; i < x; i++) {
            cin >> s;
            var.eid[i] = etoi[s];
        }
        return in;
    } 
};

vector<car> cars;

void input() {
    g.clear();
    cars.clear();
    edgeBegin.clear();

    inp(d, n, m, c, f);
    cars.resize(c);
    
    string s;
    int u, v, w, cur_id, id = 0;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> s >> w;
        if(!etoi.count(s)) {
            etoi[s] = id;
            itoe[id] = s;
            id++;
        }
        cur_id = etoi[s];
        g[u][cur_id] = {v, w};
        edgeBegin[cur_id] = u;
    }

    cin >> cars;
}

void greedySortOnLessStreets() {
    int cnt = 0;
    vector<vector<pii>> _ans(n), ans(n);

    sort(cars.begin(), cars.end(), [&](const car &lhs, const car &rhs) {
        if(lhs.p == rhs.p) return rnd(0, 1) == 1;
        return lhs.p < rhs.p;
    });

    auto busy = [&](int u, int sec) {
        int sz = ans[u].size();
        for(int i = 0; i < sz; i++) {
            if(ans[u][i].second == sec)
                return true;
        }
        return false;
    };

    for(int i = 0; i < c; i++) {
        int sec = 0, cur_id, u, j;
        vector<vector<int>> schedule;
        vector<int> route = cars[i].eid;
        for(int j = 0; j < route.size(); j++) {
            cur_id = route[j];
            u = edgeBegin[cur_id];
            const auto &[v, w] = g[u][cur_id];
            while(busy(u, sec)) {sec++;}
            sec += w;
            if(d < sec) break;
            schedule.push_back({v, sec, cur_id});
        }

        // include in ans
        if(schedule.size() == route.size()) {
            for(const auto &v: schedule) {
                u = v[0];
                sec = v[1];
                cur_id = v[2];
                ans[u].push_back({cur_id, sec});
            }
        }
    }

    cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += ans[i].size() >= 1;

    _ans = ans;
    ans = vector<vector<pii>>(n);
    for(int i = 0; i < n; i++) {
        // _ans[i] -> vector<pii>
        int sz = _ans[i].size();
        if(sz == 1) {
            ans[i] = _ans[i];
        } else if(sz >= 2) {
            int id = 0;
            map<int, int> mp, ind;
            for(const auto &pr: _ans[i]) {
                if(!ind.count(pr.first)) {
                    ind[id] = pr.first;
                    id++;
                }
                mp[pr.first]++;
            }

            for(int j = 0; j < id; j++) {
                int key = ind[j];
                ans[i].push_back({key, mp[key]});
            }
        }
    }

    cout << cnt << endl;
    for(int i = 0; i < n; i++) {
        if(!ans[i].empty()) {
            cout << i << endl;
            cout << ans[i].size() << endl;
            for(const auto &pr: ans[i])
                cout << itoe[pr.first] << " " << pr.second << endl;
        }
    }
}

void solve(int tc)
{
    input();
    greedySortOnLessStreets();
}