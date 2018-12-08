#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		string binary = "";
		string init_binary = "";
		uint32_t mok, namogi, result = 0;

		if (n == 0)
			return 0;

		mok = n;

		while (mok != 1)
		{
			namogi = mok % 2;

			binary += to_string(namogi);

			mok /= 2;
		}

		binary += to_string(mok);

		int init_length = 32 - binary.length();

		for (auto i = 0; i < init_length; ++i)
		{
			init_binary += to_string(0);
		}

		binary += init_binary;

		int weight = 1;

		result += (binary[binary.length() - 1] - '0');

		for (auto i = binary.length() - 2; i > -1; --i)
		{
			weight *= 2;
			result += weight * (binary[i] - '0');
		}

		return result;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		int ret = Solution().reverseBits(n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}