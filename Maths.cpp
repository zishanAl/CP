/*
---------------------------------------------------
Modular Arithmetic Template
Time Complexity:
  - power(a, b): O(log b)
  - precomputeFactorials(N): O(N)
  - nCr(n, r): O(log MOD) (because of modular inverse)
Space Complexity:
  - O(N) for factorial array
---------------------------------------------------
*/

const int MOD = 1e9 + 7;
static constexpr int MAXN = 1e4; // max limit for factorial
long long fact[MAXN + 1];

long long power(long long a, long long b, long long mod) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

long long modularnCr(int n, int r) {
      if (r < 0 || r > n) return 0;

      // precompute factorial
      fact[0] = 1;
      for(int i = 1; i <= MAXN; i++) fact[i] = (fact[i-1] * i) % MOD;

      long long A = fact[n];                       // n!
      long long B = (fact[r] * fact[n - r]) % MOD; // r! * (n-r)!

      long long B_inv = power(B, MOD - 2, MOD);

      return (A * B_inv) % MOD;
  }
