package leetcode;

import java.util.TreeMap;

/**
 * @author manki.kim
 **/
public class HandOfStraights {

	public static void main(String... args) {
		int[] arr = {2, 1};
		System.out.println(isNStraightHand(arr, 2));
	}

	public static boolean isNStraightHand(int[] hand, int W) {
		TreeMap<Integer, Integer> map = new TreeMap<>();

		if (hand.length % W != 0) {
			return false;
		}

		for (int num : hand) {
			int count = map.getOrDefault(num, 0);
			map.put(num, count + 1);
		}

		while (map.size() > 0) {
			int firstKey = map.firstKey();
			for (int i = 0; i < W; i++) {
				int currentKey = firstKey + i;
				if (!map.containsKey(currentKey)) {
					return false;
				}
				if (map.get(currentKey) == 1) {
					map.remove(currentKey);
				} else {
					map.put(currentKey, map.get(currentKey) - 1);
				}
			}
		}
		return true;
	}
}
