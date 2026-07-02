#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            }
            else if (sum > 0) {
                right--;
            }
            else {

                ans.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                // Skip duplicate values
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    cout << "Triplets are:\n";

    for (auto triplet : ans) {

        cout << "[ ";

        for (int num : triplet) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}