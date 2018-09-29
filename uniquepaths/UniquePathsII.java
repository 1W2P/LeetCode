/**
 * @author manki.kim
 * @see https://leetcode.com/problems/unique-paths-ii/description/
 **/
public class UniquePathsII {
	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		int col = obstacleGrid.length;
		int row = obstacleGrid[0].length;

		if (obstacleGrid[col - 1][row - 1] == 1) {
			return 0;
		}

		int[][] dp = new int[col + 1][row + 1];
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (obstacleGrid[i][j] != 1) {
					dp[i + 1][j] += dp[i][j];
					dp[i][j + 1] += dp[i][j];
				}
			}
		}

		return dp[col - 1][row - 1];
	}
}
