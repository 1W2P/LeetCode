package leetcode;

/**
 * @author manki.kim
 **/
public class MaxProfit {

	public static void main(String... args) {
		int[] arr = {7,6,4,3,1};
		System.out.println(maxProfit(arr));
	}

	public static int maxProfit(int[] prices) {
		if (prices.length == 0) {
			return 0;
		}
		int maxProfit = 0;
		int minDay = prices[0];

		for (int i = 1; i < prices.length; i++) {
			maxProfit = Math.max(prices[i] - minDay, maxProfit);
			minDay = Math.min(minDay, prices[i]);
		}

		return maxProfit;
	}
}
