#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        
        // iterates over the array.
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // checks if the complement exists in the map.
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            
            // if not, store the current number with its index.
            numToIndex[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    // example 
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Index1: " << result[0] << ", Index2: " << result[1] << "\n";
    } else {
        cout << "No two sum solution found.\n";
    }

    return 0;
}