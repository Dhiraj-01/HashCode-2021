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
    vector<string> ingredients;
    void scan()
    {
        ll x;
        cin >> x;
        ingredients.resize(x);
        for(ll i = 0; i < x; i++) {
            cin >> ingredients[i];
        }
    }
};
string to_string(const Pizza &p)
{
    string res = "";
    #ifdef Dhiraj
    {
        res += "[";
        res += to_string(p.id);
        res += ", " + to_string(p.ingredients);
        res += "]";
    }
    #endif
    return res;
}

struct Input
{
    ll M, T2, T3, T4;
    vector<Pizza> p, pp;
    void scan()
    {
        cin >> M >> T2 >> T3 >> T4;
        p.resize(M);
        for(ll i = 0; i < M; i++) {
            p[i].id = i;
            p[i].scan();
        }
        pp = p; // pp just a copy of p, do whatever you want to do with pp
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

    ll MM = in.M;
    ll id_i = 0, id_j = in.M - 1;

    /* input - B
     
    auto f = [&](ll x)
    {
        ll mx_score = 0;
        vector<ll> ans{};
        for(ll i = 0; i < in.M; i++)
        {
            if(vis[i]) continue;
            for(ll j = i + 1; j < in.M; j++)
            {
                if(vis[j]) continue;
                if(x == 2) {
                    if(total(i, j) >= mx_score) {

                    }
                    mx_score = Max(i, j);
                    continue;
                }
            }
        }
        if(x == 1)
        return ans;
    };

    vector<bool> vis(MM, 0);
    for(ll i = 0; i < MM; i++)
    {
        if(vis[i]) continue;
        ll mx_score = 0;
        for(ll j = i + 1; j < MM; j++)
        {

            // (i, j)
        }
    }
    return;
    /*

    shuffle(in.pp.begin(), in.pp.end(), rng);
    
    while(MM > 0)
    {
        ll r = rnd(0, 10);
        if(r == 0 and MM >= 2 and in.T2 > 0)
        {
            assert(id_i < in.M);
            assert(id_j >= 0);

            out.D++;
            vector<ll> del;
            del.emplace_back(2);
            del.emplace_back(in.pp[id_i].id);
            del.emplace_back(in.pp[id_j].id);
            out.deliveries.emplace_back(del);

            in.T2--;
            id_i += 1;
            id_j -= 1;
            MM -= 2;
        }
        else if(r == 1 and MM >= 3 and in.T3 > 0)
        {
            assert(id_i < in.M);
            assert(id_j - 1 >= 0);

            out.D++;
            vector<ll> del;
            del.emplace_back(3);
            del.emplace_back(in.pp[id_i].id);
            del.emplace_back(in.pp[id_j].id);
            del.emplace_back(in.pp[id_j - 1].id);
            out.deliveries.emplace_back(del);

            in.T3--;
            id_i += 1;
            id_j -= 2;
            MM -= 3;
        }
        else if(r == 2 and MM >= 4 and in.T4 > 0)
        {
            assert(id_i < in.M);
            assert(id_j - 2 >= 0);

            out.D++;
            vector<ll> del;
            del.emplace_back(4);
            del.emplace_back(in.pp[id_i].id);
            del.emplace_back(in.pp[id_j].id);
            del.emplace_back(in.pp[id_j - 1].id);
            del.emplace_back(in.pp[id_j - 2].id);
            out.deliveries.emplace_back(del);

            in.T4--;
            id_i += 1;
            id_j -= 3;
            MM -= 4;
        }
        else if(0) {
            // 2, 3, 4
            if(MM >= 2 and in.T2 > 0)
            {
                assert(id_i < in.M);
                assert(id_j >= 0);

                out.D++;
                vector<ll> del;
                del.emplace_back(2);
                del.emplace_back(in.pp[id_i].id);
                del.emplace_back(in.pp[id_j].id);
                out.deliveries.emplace_back(del);

                in.T2--;
                id_i += 1;
                id_j -= 1;
                MM -= 2;
            }
            else if(MM >= 3 and in.T3 > 0)
            {
                assert(id_i < in.M);
                assert(id_j - 1 >= 0);

                out.D++;
                vector<ll> del;
                del.emplace_back(3);
                del.emplace_back(in.pp[id_i].id);
                del.emplace_back(in.pp[id_j].id);
                del.emplace_back(in.pp[id_j - 1].id);
                out.deliveries.emplace_back(del);

                in.T3--;
                id_i += 1;
                id_j -= 2;
                MM -= 3;
            }
            else if(MM >= 4 and in.T4 > 0)
            {
                assert(id_i < in.M);
                assert(id_j - 2 >= 0);

                out.D++;
                vector<ll> del;
                del.emplace_back(4);
                del.emplace_back(in.pp[id_i].id);
                del.emplace_back(in.pp[id_j].id);
                del.emplace_back(in.pp[id_j - 1].id);
                del.emplace_back(in.pp[id_j - 2].id);
                out.deliveries.emplace_back(del);

                in.T4--;
                id_i += 1;
                id_j -= 3;
                MM -= 4;
            }
            else break;
        }
        else
        {
            // 4 3 2
            if(MM >= 4 and in.T4 > 0)
            {
                assert(id_i < in.M);
                assert(id_j - 2 >= 0);

                out.D++;
                vector<ll> del;
                del.emplace_back(4);
                del.emplace_back(in.pp[id_i].id);
                del.emplace_back(in.pp[id_j].id);
                del.emplace_back(in.pp[id_j - 1].id);
                del.emplace_back(in.pp[id_j - 2].id);
                out.deliveries.emplace_back(del);

                in.T4--;
                id_i += 1;
                id_j -= 3;
                MM -= 4;
            }
            else if(MM >= 3 and in.T3 > 0)
            {
                assert(id_i < in.M);
                assert(id_j - 1 >= 0);

                out.D++;
                vector<ll> del;
                del.emplace_back(3);
                del.emplace_back(in.pp[id_i].id);
                del.emplace_back(in.pp[id_j].id);
                del.emplace_back(in.pp[id_j - 1].id);
                out.deliveries.emplace_back(del);

                in.T3--;
                id_i += 1;
                id_j -= 2;
                MM -= 3;
            }
            else if(MM >= 2 and in.T2 > 0)
            {
                assert(id_i < in.M);
                assert(id_j >= 0);

                out.D++;
                vector<ll> del;
                del.emplace_back(2);
                del.emplace_back(in.pp[id_i].id);
                del.emplace_back(in.pp[id_j].id);
                out.deliveries.emplace_back(del);

                in.T2--;
                id_i += 1;
                id_j -= 1;
                MM -= 2;
            }
            else break;
        }
    }
    return out;
}

ll Score(const Input &in, const Output &out)
{
    ll score = 0;
    for(ll i = 0; i < out.D; i++)
    {
        set<string> s;
        for(ll j = 1; j <= out.deliveries[i][0]; j++)
        {
            for(const string &ss : in.p[out.deliveries[i][j]].ingredients) {
                s.emplace(ss);
            }
        }
        score += (s.size() * s.size());
    }
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

    // sort(in.pp.begin(), in.pp.end(), [](const Pizza &lhs, const Pizza &rhs)
    // {
    //     unordered_set<string> lhs_s, rhs_s;
    //     for(const string &ss : lhs.ingredients) {
    //         lhs_s.emplace(ss);
    //     }
    //     for(const string &ss : rhs.ingredients) {
    //         rhs_s.emplace(ss);
    //     }
    //     return lhs_s.size() > rhs_s.size();
    // });

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
        d(rep, cur_score, best_score);
    }
    d(redable(best_score));
    best_out.print();
}

int main()
{
    // #ifdef Dhiraj
    //     freopen("./i4.txt", "r", stdin);
    //     freopen("./o4.txt", "w", stdout);
    // #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    for(int i = 1; i <= tc; i++) {
        solve(i);
    }
    return 0;
}