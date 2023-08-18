#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")
#define Noo printf("-1\n")
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pi acos(-1)
#define piii pair<int, pii>
#define min_heap priority_queue<int, vector<int>, greater<int>>
const ll M = 1610612741;
long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}
const ll inf = 1e18;
const int N = 1610612741;
#define vll vector<long long>
#define mll map<long long, long long>
long long modularExponentiation(long long a, long long b, long long m)
{
    long long result = 1;
    a = a % m;

    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % m;

        a = (a * a) % m;
        b >>= 1;
    }

    return result;
}

long long ncr(long long n, long long r, long long m = M)
{
    if (r > n - r)
        r = n - r;

    long long numerator = 1;
    long long denominator = 1;

    for (long long i = 1; i <= r; i++)
    {
        numerator = (numerator * (n - i + 1)) % m;
        denominator = (denominator * i) % m;
    }

    long long inverseDenominator = modularExponentiation(denominator, m - 2, m);

    long long result = (numerator * inverseDenominator) % m;
    return result;
}
ll dp[1000001];
ll inv[1000001];
void init(string input)
{
    ll p = 31;
    ll p_pow = 1;
    inv[0] = 1;
    dp[0] = (input[0] - '0' + 1);
    for (ll i = 1; i < input.size(); i++)
    {
        char ch = input[i];
        p_pow = (p_pow * p) % M;
        inv[i] = modularExponentiation(p_pow, M - 2, M);
        dp[i] = (dp[i - 1] + (ch - '0' + 1) * p_pow) % M;
    }
}
ll substring(ll l, ll r)
{
    ll res = dp[r];
    if (l > 0)
        res -= dp[l - 1];
    res = (res * inv[l]) % M;
    if (res < 0)
        res += M;
    return res;
}

void solve()
{
    string s;
    cin >> s;
    init(s);

    ll ans = 0;
    for (ll i = 0, j = s.size() - 1; i <= j; i++, j--)
    {
        ll res = 1;
        ll tmpi = i;
        ll tmpj = j;
        while (i <= j)
        {
            if (substring(tmpi, i) == substring(j, tmpj))
            {
                res = 2;
                break;
            }
            i++;
            j--;
        }
        ans += res;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
