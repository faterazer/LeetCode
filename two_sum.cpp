/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum_mark1(vector<int>&, int);
    vector<int> twoSum_mark2(vector<int>&, int);
    vector<int> twoSum_mark3(vector<int>&, int);
};

int main(int argc, char const *argv[])
{
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    Solution s;

    vector<int> result = s.twoSum_mark1(nums, target);
    for (const auto &a : result)
        cout << a << " ";
    cout << endl;
        
    return 0;
}

// Brute Force. Slowest.
vector<int> Solution::twoSum_mark1(vector<int>& nums, int target)
{
    vector<int> result;
	for (size_t i = 0; i < nums.size(); i++) {
		for (size_t j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				result.emplace_back(i);
				result.emplace_back(j);
				return result;
			}
		}
	}
	return result;
}

// Two-pass Hash Table.
vector<int> Solution::twoSum_mark2(vector<int> &nums, int target)
{
    map<int, int> temp_map;
	for (size_t i = 0; i < nums.size(); i++)
		temp_map[nums[i]] = i;

	vector<int> result;
	for (size_t i = 0; i < nums.size(); i++) {
		int complement = target - nums[i];
		if (temp_map.find(complement) != temp_map.end() && temp_map[complement] != i) {
			result.emplace_back(i);
			result.emplace_back(temp_map[complement]);
			return result;
		}
	}
	return result;
}

// One-pass Hash Table. Fastest.
vector<int> Solution::twoSum_mark3(vector<int> &nums, int target)
{
    map<int, int> numbers;
    vector<int> result;

    for (size_t i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numbers.find(complement) != numbers.end()) {
            result.emplace_back(numbers[complement]);
            result.emplace_back(i);
            return result;
        }
        numbers[nums[i]] = i;
    }

    return result;
}