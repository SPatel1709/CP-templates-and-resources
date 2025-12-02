#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M=1e9+7;

// Binary Exponentiation -> O(log(b))
ll binExp(ll a, ll b, ll M) {
    ll ans = 1;
    while (b) {
        if (b&1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

ll mult(ll a,ll b)
{
    return ((a%M)*(b%M))%M;
}

// Combinatorics
const int N = 1e5 + 10;
ll fact[N], modinv[N];

//modular inverse is (a^-1)%mod=(a^(mod-2))%mod
void precomp() {
    fact[0] = 1, modinv[0] = 1;
    for (int i=1; i<N; i++) {
        fact[i] = (fact[i-1] * i) % M;
        modinv[i] = binExp(fact[i], M-2, M);
    }
}

ll comb(ll n, ll r) {
    if (r>n || r<0 || n<0) return 0;
    ll numo = fact[n];
    ll denoinv = (modinv[r] * modinv[n-r]) % M;
    ll ans = (numo * denoinv) % M;
    return ans;
}