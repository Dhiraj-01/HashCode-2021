#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

// other structures here
// ex. Pizza, Books etc accoring to problem

struct Input
{
    // all input variables
    void scan() {
        // scan complete input, according to problem
    }
};
struct Output
{
    // all outputs variables
    void print() {
        // print accroding to problem
    }
};

Output Solver(Input in)
{
    Output out;
    // your code here ...

    return out;
}

ll Score(const Input &in, const Output &out)
{
    ll score = 0;
    // calculate score for current output
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
    // cerr << "score : " << Score(in, out) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for(int i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}

/* Other important points
- don't use any macro (except ll)
- don't use ONLINE_JUDGE macro
- use 1 based index for array
- declare same variable name as given in problem 
*/