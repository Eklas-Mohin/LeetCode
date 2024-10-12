/** **************************
 *   author:  mohin          *
 *   problem: LeetCode 204   *
 *   verdict: Accepted       *
 *****************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> sieve(n, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int prime_count = 0;
        for (int i = 2; i < n; ++i) {
            if (sieve[i]) {
                prime_count++;
            }
        }

        return prime_count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Solution obj;
    int prime_count = obj.countPrimes(n);
    
    cout << prime_count << endl;

    return 0;
}
