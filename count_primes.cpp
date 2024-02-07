/* problem link --> https://leetcode.com/problems/count-primes/description/ */

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
    int n{}, prime_count{};
    cin >> n;
    Solution ans;
    prime_count = ans.countPrimes(n);
    cout << prime_count << endl;
    return 0;
}
