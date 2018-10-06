package leetcode;

import java.util.Stack;

/**
 * @author manki.kim
 *
 * O(n), O(nlogn) 수준으로 풀려면 정렬을 하지 않아야 한다
 * 연속된 새로운 부분 집합은 매번 1개씩 증가한다
 * 3
 * 1, 3 1
 * 2, 1 2, 3 1 2
 * 4, 2 4, 1 2 4, 3 1 2 4
 * 8, 4 8, 2 4 8, 1 2 4 8, 3 1 2 4 8
 * 5, 8 5, 4 8 5, 2 4 8 5, 1 2 4 8 5, 3 1 2 4 8 5
 *
 *
 * 스택에는 모든 값들을 넣지만
 * 결국에는 현재 내 인덱스의 값보다 작은 값들 만 들어있다
 * 이렇게 보관하는 이유는
 * 신규 부분집합에서 기존에 존재하는 현재 값보다 더 작은 최소 값으로 이루어진 부분 집합은 제외하고
 * 나머지 즉
 * 4, 2 4, 1 2 4, 3 1 2 4 같은 경우는
 * 부분집합 4만 더하고 나머지는 기존의 최소값을 활용해야 하기 떄문
 *
 *
 **/
public class SumOfSubarrayMinimums {

	public static void main(String... args) {
		int[] arr = {3, 1, 2, 4};

		System.out.println(sumSubarrayMins(arr));
	}

	public static int sumSubarrayMins(int[] A) {
		int sum = 0;
		int mod = 1000000000 + 7;

		Stack<Integer> stack = new Stack<>();
		int[] subsetDP = new int[A.length];
		for (int i = 0; i < A.length; i++) {
			// 스택 값 중에 현재 값 보다 더 큰 애들은 제외 시킨다 -> 현재 값으로 대체 가능하기 때문
			while (!stack.isEmpty() && A[i] < A[stack.peek()]) {
				stack.pop();
			}

			int sumOfNewSubset;
			if (stack.isEmpty()) {
				// 현재 값이 가장 최소값인 경우 즉 3, 5, 7 ,8, 1 일때 현재 값이 1인 경우 -> 새로 생기는 모든 부분집합의 값을 1로 대체 가능
				sumOfNewSubset = (i + 1) * A[i];
			} else {
				// 현재 값이 가장 최소값은 아닌 경우 3, 5, 7 ,4 에서 4인 경우 새로 생기는 부분 집합 중에 5, 7만 포함 되는 경우는 4로 대체 가능 하지만 3이 포함 된 부분 집합은 안되가 때문에 기존에 3이 포함된 부분집합의 최소 값을 미리 구한 것을 더해준다.
				int lastMinValueIndex = stack.peek();
				sumOfNewSubset = subsetDP[lastMinValueIndex] + (i - lastMinValueIndex) * A[i];

			}

			// 현재 값이 포함된 부분집합의 최소 값을 저장
			subsetDP[i] = sumOfNewSubset;
			sum = (sum  + sumOfNewSubset) % mod;

			//인덱스를 저장 하는 이유는 위의 else문을 계산하기 위해 즉 3, 5, 7 ,4에서 3을 뺀 5, 7, 4에서 5 또는 7로만 구성되어 있는 집합 개수를 구하기 위해서... 5, 7, 4 | 7, 4 | 4
			stack.push(i);
		}

		return sum;
	}
}
