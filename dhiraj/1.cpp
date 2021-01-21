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
        p.resize(M + 1);
        for(ll i = 1; i <= M; i++) {
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
            for(ll x : del) {
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
    while(in.M > 0)
    {
        if(in.T2 > 0 and in.M >= 2)
        {
            out.D++;
            vector<ll> del;
            del.emplace_back(2);
            del.emplace_back(id);
            del.emplace_back(id + 1);
            out.deliveries.emplace_back(del);
            id += 2;
            in.T2--;
            in.M -= 2;
        }
        else if(in.T3 > 0 and in.M >= 3)
        {
            out.D++;
            vector<ll> del;
            del.emplace_back(3);
            del.emplace_back(id);
            del.emplace_back(id + 1);
            del.emplace_back(id + 2);
            out.deliveries.emplace_back(del);
            id += 3;
            in.T3--;
            in.M -= 3;
        }
        else if(in.T2 > 0 and in.M >= 4)
        {
            out.D++;
            vector<ll> del;
            del.emplace_back(4);
            del.emplace_back(id);
            del.emplace_back(id + 1);
            del.emplace_back(id + 2);
            del.emplace_back(id + 3);
            out.deliveries.emplace_back(del);
            id += 4;
            in.T4--;
            in.M -= 4;
        }
        else break;
    }
    return out;
}

void solve(int &tc)
{
    Input in;
    in.scan();
    solver(in).print();
}

int main()
{
    #ifdef Dhiraj
        freopen("D:/dhiraj/Github/HashCode-2021/dhiraj/i1.txt", "r", stdin);
        freopen("D:/dhiraj/Github/HashCode-2021/dhiraj/o1.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for(int i = 1; i <= tc; i++) {
        cerr << "Case #" << i << "\n";
        solve(i);
    }
    return 0;
}