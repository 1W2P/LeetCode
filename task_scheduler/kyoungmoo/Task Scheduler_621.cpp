#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare_pair(pair<char, int> x, pair<char, int> y)
{
	return x.second > y.second;
}

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<pair<char, int>> task_vector;
		map<char, int> tasks_count;
		map<char, int> tasks_map;
		bool is_action = false;
		vector<char> result;

		for (auto i = 0; i < tasks.size(); ++i)
		{
			tasks_count[tasks[i]]++;
			tasks_map[tasks[i]] = -1;
		}

		for (auto it = tasks_count.begin(); it != tasks_count.end(); ++it)
		{
			task_vector.push_back(make_pair(it->first, it->second));
		}

		sort(task_vector.begin(), task_vector.end(), compare_pair);

		while (!task_vector.empty())
		{
			is_action = false;

			auto x = task_vector.front();
			task_vector.erase(task_vector.begin());

			if (tasks_map[x.first] <= 0)
			{
				result.push_back(x.first);

				tasks_map[x.first] = n;
				if (--x.second > 0)
				{
					task_vector.push_back(make_pair(x.first, x.second));
				}

				for (auto it = tasks_map.begin(); it != tasks_map.end(); ++it)
				{
					if (it->first != x.first)
					{
						--(it->second);
					}
				}

				sort(task_vector.begin(), task_vector.end(), compare_pair);
				is_action = true;
			}
			else
			{
				task_vector.push_back(x);

				for (int i = 0; i < task_vector.size(); ++i)
				{
					if (tasks_map[task_vector[i].first] != tasks_map[x.first] && tasks_map[task_vector[i].first] <= 0)
					{
						is_action = true;
						break;
					}
				}
			}

			if (!is_action)
			{
				for (auto i = tasks_map.begin(); i != tasks_map.end(); ++i)
				{
					--(i->second);
				}
				result.push_back('h');
			}
		}

		return result.size();
	}
};

int main(void)
{
	vector<char> tasks;

	tasks.push_back('A');
	tasks.push_back('A');
	tasks.push_back('A');
	tasks.push_back('B');
	tasks.push_back('B');
	tasks.push_back('B');

	cout << Solution().leastInterval(tasks, 2) << endl;
	return 0;
}