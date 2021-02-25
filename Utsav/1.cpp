#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

struct Input
{
    void scan() {
    }
};

struct Output
{
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

void solve()
{
    Input in;
    in.scan();
    
    Output out = Solver(in);
    out.print();
    
    ll score = Score(in, out);
    d(redable(score));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for(int i = 1; i <= tc; i++) {
        solve(i);
    }
    return(0);
}
