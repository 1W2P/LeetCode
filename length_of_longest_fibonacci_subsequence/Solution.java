import java.util.*;

public class Solution {
  public static void main(String[] args) {
    int[] test1 = { 1, 2, 3, 4, 5, 6, 7, 8 };// 5
    // [1,2,3,5,8]
    int[] test2 = { 1, 3, 7, 11, 12, 14, 18 };// 3
    // [1,11,12], [3,11,14] or [7,11,18].
    // System.out.println(lenLongestFibSubseq(test1));
    System.out.println("===========================");
    System.out.println(lenLongestFibSubseq(test2));
  }

  public static int lenLongestFibSubseq(int[] A) {
    // key : index , value : A[i]
    Map<Integer, Integer> inputArr = new HashMap<>(); // newmap.containsValue("point"));
    int i, j;
    int answer = 0;
    int aLen = A.length;
    int index = 0;
    for (int v : A) {
      inputArr.put(v, index);
      index++;
    }

    for (i = 0; i < aLen; i++) {
      for (j = i + 1; j < aLen - 1; j++) {
        int prevValue = A[i];
        int nextValue = A[j];
        int sumTwoValue = prevValue + nextValue;
        int tmpAnswerLen = 2;
        // 2 3 4 5 6
        // 2 : prevValue , 3:nextValue
        // sumTwoValue = 2+3;
        // 5 + 3

        // 8 + 5
        while (inputArr.containsKey(sumTwoValue)) {
          if (inputArr.get(sumTwoValue) < j)
            break;
          int tmp = nextValue;
          int tmp2 = sumTwoValue;
          sumTwoValue += tmp;
          nextValue = tmp2;
          tmpAnswerLen++;
          answer = Math.max(answer, tmpAnswerLen);

        }
      }
    }
    return (answer >= 3) ? answer : 0;
  }
}