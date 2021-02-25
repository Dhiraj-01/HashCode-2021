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
    ll P;
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
        car.resize(S);
        for(ll i = 0; i < V; i++) {
            car[i].read();
        }
    }
};

struct Output
{
    ll A;
    void print() {
    }
};

Output Solver(Input in)
{
    Output out;
    return out;
}

ll Score(const Input &in, const Output &out)
{
    ll score = 0;
    return score;
}

string redable(ll score) // 1234 => 1,234
{
    string s = to_string(score);
    string res = "";
    for(ll i = 0; i < s.size(); i++) {
        res += s[i];
        if((s.size() - i - 1) % 3 == 0) {
            res += ',';
        }
    }
    res.pop_back();
    return res;
}

void solve(int &tc)
{
    Input in;
    in.scan();
    
    // Output out = Solver(in);
    // out.print();
    
    // ll score = Score(in, out);
    // d(redable(score));
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
