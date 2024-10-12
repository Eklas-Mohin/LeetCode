/** **************************
 *   author:  mohin          *
 *   problem: LeetCode 1     *
 *   verdict: Accepted       *
 *****************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> pos;

        for (int i = 0; i < nums.size(); ++i) {
            int k = target - nums[i];
            if (pos.find(k) != pos.end()) { 
                ans.push_back(pos[k]);       
                ans.push_back(i);             
                return ans;                   
            }
            pos[nums[i]] = i;
        }
        
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, target;
    vector<int> nums;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cin >> target;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);
    
    if (ans.size() == 2) {
        printf("[%d,%d]\n", ans[0], ans[1]);
    } else {
        printf("No two sum solution found\n");
    }

    return 0;
}
