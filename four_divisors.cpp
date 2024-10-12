/** **************************
 *   author:  mohin          *
 *   problem: LeetCode 1390  *
 *   verdict: Accepted       *
 *****************************/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumOfDivisors(int n)
    {
        int sum = 1;
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                int term_sum = 1, term_pow = 1;
                while (n % i == 0)
                {
                    term_pow *= i;
                    term_sum += term_pow;
                    n /= i;
                }
                sum *= term_sum;
            }
        }
        if (n > 1)
        {
            sum *= (n + 1);
        }
        return sum;
    }
    int numOfDivisor(int n)
    {
        int divisor_count = 1;
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                int count = 0;
                while (n % i == 0)
                {
                    count++;
                    n /= i;
                }
                divisor_count *= (count + 1);
            }
        }
        if (n > 1)
        {
            divisor_count *= 2;
        }
        return divisor_count;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int total_sum = 0;
        for (int num : nums)
        {
            if (numOfDivisor(num) == 4)
            {
                total_sum += sumOfDivisors(num);
            }
        }
        return total_sum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int array_size;
    cin >> array_size;
    vector<int> nums(array_size);
    for (int i = 0; i < array_size; ++i)
    {
        cin >> nums[i];
    }
    Solution obj;
    int result = obj.sumFourDivisors(nums);
    cout << result << endl;
    return 0;
}
