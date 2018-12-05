package leetcode;

/**
 * @author
 **/
public class ReverseBits {

	public static void main(String... args) {
		System.out.println(reverseBits(43261596));
	}

	public static int reverseBits(int n) {
		int result = 0;
		for (int i = 0; i < 32; i++) {
			result += (n >> i & 1) << (31 - i);
		}

		return result;
	}
}
