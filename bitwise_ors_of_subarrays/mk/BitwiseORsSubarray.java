package leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * @author
 **/
public class BitwiseORsSubarray {

	public static void main(String... args) {
		System.out.println(subarrayBitwiseORs(new int[] {39, 19, 30, 56, 79, 50, 19, 70, 30}));
	}

	public static int subarrayBitwiseORs(int[] A) {
		List<Set<Integer>> orOfEachStep = new ArrayList<>();
		orOfEachStep.add(new HashSet<>());
		orOfEachStep.get(0).add(A[0]);
		for (int i = 1; i < A.length; i++) {
			orOfEachStep.add(new HashSet<>());
			orOfEachStep.get(i).add(A[i]);
			for (Integer e : orOfEachStep.get(i - 1)) {
				orOfEachStep.get(i).add(e | A[i]);
			}
		}

		return orOfEachStep.stream()
			.flatMap(Set::stream)
			.collect(Collectors.toSet())
			.size();
	}
}
