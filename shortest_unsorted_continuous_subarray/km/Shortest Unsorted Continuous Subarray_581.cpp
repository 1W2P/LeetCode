#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<bool> is_sort;
		int start = 0;
		int end = 0;
		
		for (auto i = 0; i < nums.size(); ++i)
		{
			is_sort.push_back(false);
		}

		for (auto i = 0; i < nums.size(); ++i)
		{
			auto least = i;

			for (auto j = i+1; j < nums.size(); ++j)
			{
				if (nums[least] > nums[j])
					least = j;
			}

			if (least != i)
			{
				swap(nums[least], nums[i]);
				is_sort[i] = is_sort[least] = true;
			}
		}
		/*
		for (auto i = 0; i < nums.size(); ++i)
		{
			for (auto j = 0; j < nums.size() - (i + 1); ++j)
			{
				if (nums[j] > nums[j+1])
				{
					swap(nums[j], nums[j + 1]);
					is_sort[j] = is_sort[j+1] = true;
				}
			}
		}
		*/
		for (auto i = 0; i < is_sort.size(); ++i)
		{
			if (is_sort[i])
			{
				start = i;
				break;
			}
		}
		/*
		 * [2, 6, 4, 8, 10, 9, 15]
		 */
		for (auto i = is_sort.size() - 1; i > 0; --i)
		{
			if (is_sort[i])
			{
				end = i;
				break;
			}
		}

		if (end == 0 && start == 0)
			return 0;

		return end - start + 1;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().findUnsortedSubarray(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}