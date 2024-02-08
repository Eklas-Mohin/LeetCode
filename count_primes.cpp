/**
 *    author: mohin    
**/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        bool sieve[5000001];
        memset(sieve, true, sizeof(sieve));
        int prime_count{};
        sieve[0] = sieve[1] = false;
        for (int i = 4; i <= n; i += 2) {
            sieve[i] = false;
        }
        for (int i = 3; i <= sqrt(n + 1); i += 2) {
            if (sieve[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        if (n > 2) {
            prime_count = 1;
        }
        for (int i = 3; i < n; i += 2) {
            if (sieve[i]) {
                prime_count += 1;
            }
        }
        return prime_count;
    }
};

// Driver code
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n{}, prime_count{};
    cin >> n;
    Solution obj;
    prime_count = obj.countPrimes(n);
    cout << prime_count << endl;
    return 0;
}
