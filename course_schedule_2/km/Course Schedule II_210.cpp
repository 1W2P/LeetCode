#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<vector<int>> board;
		queue<int> q;
		vector<int> result;

		if (prerequisites.empty())
			return result;
		
		board.resize(numCourses);

		for (auto i = 0; i < numCourses; ++i)
		{
			board[i].resize(numCourses);
		}

		int size = prerequisites.size();
		int n = size;
		for (auto i = 0; i < size; ++i)
		{
			board[prerequisites[i].second][prerequisites[i].first] = 1;

			if (board[prerequisites[i].first][prerequisites[i].second] == 1)
			{
				n--;
			}
		}

		int count = n;
		int index = 0;
		vector<bool> is_visit;

		while (count > 0)
		{
			queue<int>().swap(q);
			vector<int>().swap(result);
			vector<bool>().swap(is_visit);
			count = n;

			for (auto i = 0; i < numCourses; ++i)
			{
				is_visit.push_back(false);
			}

			q.push(index);
			result.push_back(index);
			is_visit[index] = true;
			count--;

			while (!q.empty())
			{
				auto n = q.front();
				q.pop();

				for (auto i = 0; i < board[n].size(); ++i)
				{
					if (board[n][i] == 1 && !is_visit[i])
					{
						q.push(i);
						result.push_back(i);
						is_visit[i] = true;
						count--;

						if (count == 0)
						{
							queue<int>().swap(q);
							break;
						}
					}
				}
			}
			index++;
		}

		return result;
	}
};

int main(void)
{
	vector<pair<int, int>> input;

	input.push_back(make_pair(2, 0));
	input.push_back(make_pair(1, 0));
	//input.push_back(make_pair(3, 1));
	input.push_back(make_pair(3, 2));
	//input.push_back(make_pair(1, 3));

	auto result = Solution().findOrder(4, input);

	for (auto i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}

	return 0;
}