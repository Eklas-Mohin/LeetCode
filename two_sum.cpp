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
        vector<int> result;
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); ++i) {
            int k = target - nums[i];
            if (pos.find(k) != pos.end()) { 
                result.push_back(pos[k]);       
                result.push_back(i);             
                return result;                   
            }
            pos[nums[i]] = i;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n, x, target;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cin >> target;
    Solution obj;
    vector<int> result = obj.twoSum(nums, target);
    if (result.size() == 2) {
        printf("[%d,%d]\n", result[0], result[1]);
    } else {
        printf("No two sum solution found\n");
    }
    return 0;
}
