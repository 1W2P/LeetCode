#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) 
	{
		int size = height.size();
		int left = 0, right = size - 1;
		int result = 0;

		while (left < right)
		{
			result = max(result, min(height[left], height[right]) * (right - left));

			if (height[left] > height[right])
			{
				right--;
			}
			else
			{
				left++;
			}
		}

		return result;
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
		vector<int> height = stringToIntegerVector(line);

		int ret = Solution().maxArea(height);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}