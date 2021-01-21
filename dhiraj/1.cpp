#include <bits/stdc++.h>
using namespace std;

#ifdef Dhiraj
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

struct Pizza
{
    ll id;
    vector<string> ingre;
    void scan()
    {
        ll x;
        cin >> x;
        ingre.resize(x);
        for(ll i = 0; i < x; i++) {
            cin >> ingre[i];
        }
    }
};

struct Input
{
    ll M, T2, T3, T4;
    vector<Pizza> p;
    void scan()
    {
        cin >> M >> T2 >> T3 >> T4;
        p.resize(M);
        for(ll i = 0; i < M; i++) {
            p[i].id = i;
            p[i].scan();
        }
    }
};
struct Output
{
    ll D;
    vector<vector<ll>> deliveries;
    Output() {
        D = 0;
        deliveries.clear();
    }
    void print() {
        cout << D << endl;
        for(auto &del : deliveries) {
            for(ll &x : del) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
};

Output solver(Input in)
{
    Output out;

    ll id = 0;
    vector<Pizza> pp = in.p;
    shuffle(pp.begin(), pp.end(), rng);
    
    while(id < in.M)
    {
        if(in.T2 > 0 and id + 1 < in.M)
        {
            out.D++;
            vector<ll> del;
            del.emplace_back(2);
            del.emplace_back(pp[id].id);
            del.emplace_back(pp[id + 1].id);
            out.deliveries.emplace_back(del);
            id += 2;
            in.T2--;
        }
        else if(in.T3 > 0 and id + 2 < in.M)
        {
            out.D++;
            vector<ll> del;
            del.emplace_back(3);
            del.emplace_back(pp[id].id);
            del.emplace_back(pp[id + 1].id);
            del.emplace_back(pp[id + 2].id);
            out.deliveries.emplace_back(del);
            id += 3;
            in.T3--;
        }
        else if(in.T2 > 0 and id + 3 < in.M)
        {
            out.D++;
            vector<ll> del;
            del.emplace_back(4);
            del.emplace_back(pp[id].id);
            del.emplace_back(pp[id + 1].id);
            del.emplace_back(pp[id + 2].id);
            del.emplace_back(pp[id + 3].id);
            out.deliveries.emplace_back(del);
            id += 4;
            in.T4--;
        }
        else break;
    }
    return out;
}

ll Score(const Input &in, const Output &out)
{
    ll score = 0;
    for(ll i = 0; i < out.D; i++)
    {
        set<string> s;
        for(ll j = 1; j <= out.deliveries[i].front(); j++)
        {
            for(const string &ss : in.p[out.deliveries[i][j]].ingre) {
                s.emplace(ss);
            }
        }
        score += (s.size() * s.size());
    }
    return score;
}
void solve(int &tc)
{
    Input in;
    in.scan();
    
    ll best_score = 0;
    Output best_out;
    for(ll rep = 0; rep < 100; rep++)
    {
        Output out = solver(in);
        ll cur_score = Score(in, out);
        if(cur_score > best_score)
        {
            best_out = out;
            best_score = cur_score;
        }
        // d(rep, cur_score);
    }
    d(best_score);
    best_out.print();
}

int main()
{
    // #ifdef Dhiraj
    //     freopen("D:/dhiraj/Github/HashCode-2021/dhiraj/i1.txt", "r", stdin);
    //     freopen("D:/dhiraj/Github/HashCode-2021/dhiraj/o1.txt", "w", stdout);
    // #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for(int i = 1; i <= tc; i++) {
        cerr << "Case #" << i << "\n";
        solve(i);
    }
    return 0;
}