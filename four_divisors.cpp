/**
 *    author: mohin    
**/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfDivisors(int n) {
        int count{1}, ans{1};
        for (int i = 2; i <= (sqrt(n)); ++i) {
            if (n % i == 0) {
                count = 1;
                while (n % i == 0) {
                    count += 1;
                    n /= i;
                }
                ans = ans * ((pow(i, count) - 1) / (i - 1));
            }
        }
        if (n != 1) {
            ans = ans * ((pow(n, 2) - 1) / (n - 1));
        }
        return ans;
    }
    int numOfDivisor(int n) {
        int temp{n}, count{};
        vector<int> v;
        while (temp % 2 == 0) {
            count += 1;
            temp /= 2;
        }
        if (count) {
            v.push_back(count + 1);
        }
        for (int i = 3; i <= (sqrt(temp)); i += 2) {
            if (temp % i == 0) {
                count = 0;
                while (temp % i == 0) {
                    count += 1;
                    temp /= i;
                }
                v.push_back(count + 1);
            }
        }
        count = 1;
        if (temp != 1) {
            v.push_back(2);
        }
        for (int i = 0; i < v.size(); ++i) {
            count = count * v[i];
        }
        return count;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans{};
        for (int i = 0; i < nums.size(); ++i) {
            int d = numOfDivisor(nums[i]);
            if (d == 4) {
                ans += sumOfDivisors(nums[i]);
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int array_size{}, in{};
    vector<int> nums;
    cin >> array_size;
    for (int i = 0; i < array_size; ++i) {
        cin >> in;
        nums.push_back(in);
    }
    Solution obj;
    int sum_of_divisor = obj.sumFourDivisors(nums);
    cout << sum_of_divisor << endl;
    return 0;
}
