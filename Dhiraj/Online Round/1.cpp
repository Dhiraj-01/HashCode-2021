#include <bits/stdc++.h>
using namespace std;

#ifdef DHIRAJ
    #include "D:/dhiraj/Programming/debug.h"
#else
    #define d(...) 11
    #define cerr if(0) cerr
#endif

#define ll long long int
#define endl '\n'

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline ll rnd(ll l = 0, ll r = 1E9)
{
    if(l > r) swap(l, r);
    return std::uniform_int_distribution<ll>(l, r)(rng);
    // return std::uniform_real_distribution<long double>(l, r)(rng);
}

struct Street
{
    ll B, E, L;
    string name;
    void read() {
        cin >> B >> E;
        cin >> name;
        cin >> L;
    }
};

struct Car
{
    ll P, T = 0;
    vector<string> streets;
    void read() {
        cin >> P;
        streets.resize(P);
        for(ll i = 0; i < P; i++) {
            cin >> streets[i];
        }
    }
};

struct Input
{
    ll D, I, S, V, F;
    vector<Street> street;
    vector<Car> car;
    void scan() {
        cin >> D >> I >> S >> V >> F;
        street.resize(S);
        for(ll i = 0; i < S; i++) {
            street[i].read();
        }
        car.resize(V);
        for(ll i = 0; i < V; i++) {
            car[i].read();
        }
    }
};

struct Inter
{
    ll I, E;
    vector<pair<string, ll>> street;
    Inter() {
        I = -1;
        E = 0;
        street.clear();
    }
    void print() {
        cout << I << endl;
        cout << E << endl;
        for(ll i = 0; i < E; i++) {
            cout << street[i].first << " " << street[i].second << endl;
        }
    }
};

struct Output
{
    ll A;
    vector<Inter> schedule;
    Output() {
        A = 0;
        schedule.clear();
    }
    void print() {
        cout << A << endl;
        for(ll i = 0; i < A; i++) {
            schedule[i].print();
        }
    }
};

Output Solver(Input in)
{
    Output out;

    vector<vector<string>> g(in.I);
    for(ll i = 0; i < in.S; i++) {
        g[in.street[i].E].push_back(in.street[i].name);
    }

    unordered_map<string, ll> m;
    vector<ll> fre(in.I, 0);
    for(ll i = 0; i < in.S; i++) {
        m[in.street[i].name] = in.street[i].E;
        fre[in.street[i].E]++;
    }

    vector<ll> p(in.I);
    for(ll i = 0; i < in.I; i++) {
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](const ll &lhs, const ll &rhs) {
        return fre[lhs] > fre[rhs];
    });

    out.A = 0;
    for(ll k = 0; k < in.I; k++) {
        ll i = p[k];
        if(fre[i] == 0) break;
        if(in.D <= 0) break;
        if(rnd(1, 1)) {
            out.A++;
            Inter inter;
            inter.I = i;
            for(ll j = 0; j < g[i].size() and in.D > 0; j++) {
                if(fre[m[g[i][j]]]) {
                    ll r = rnd(1, fre[m[g[i][j]]]);
                    r = min(r, in.D);
                    inter.street.push_back({g[i][j], r});
                    in.D -= r;
                }
            }
            inter.E = inter.street.size();
            out.schedule.push_back(inter);
        }
    }
    return out;
}

void solve(int &tc)
{
    Input in;
    in.scan();
    
    Output out = Solver(in);
    out.print();
}

int main()
{
    #ifdef DHIRAJ
        freopen("./i1.txt", "r", stdin);
        freopen("./o1.txt", "w", stdout);
        freopen("./e1.txt", "w", stderr);    
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for(int i = 1; i <= tc; i++) {
        solve(i);
    }
    return(0);
}
