package leetcode;

import java.util.Arrays;

/**
 * @author
 **/
public class PartitionToK {

	public boolean canPartitionKSubsets(int[] nums, int k) {
		int sum = Arrays.stream(nums).sum();
		if (sum % k != 0) {
			return false;
		}

		return isPartitionK(nums, sum / k, new boolean[nums.length], k, 0, 0);
	}

	private boolean isPartitionK(int[] nums, int targetValue, boolean[] visited, int k, int sum, int index) {
		if (k == 0) {
			return true;
		}

		if (sum > targetValue) {
			return false;
		}

		if (targetValue == sum) {
			return isPartitionK(nums, targetValue, visited, k - 1, 0, 0);
		}

		// 전체 재귀적으로 탐색 약간 백트래킹 bfs를 쓰는 것이 더 나아보임..
		for (int i = index; i < nums.length; i++) {
			if (!visited[i] && sum + nums[i] <= targetValue) {
				visited[i] = true;
				boolean result = isPartitionK(nums, targetValue, visited, k, sum + nums[i], index + 1);
				// 한 번
			if (result) {
					return true;
				} else {
					visited[i] = false;
				}

			}
		}

		return false;
	}
}
