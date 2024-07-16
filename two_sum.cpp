/**
 *    author: mohin    
**/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> pos;
        pos[nums[0]] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int k = target - nums[i];
            if (pos[k] != 0) {
                ans.push_back(pos[k] - 1);
                ans.push_back(i);
                break;
            }
            pos[nums[i]] = i + 1;
        }
        return ans;
     }
};

// Driver code
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n{}, target{}, in{};
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        nums.push_back(in);
    }
    cin >> target;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);
    printf("[%d,%d]\n", ans[0], ans[1]);

    return 0;
}
