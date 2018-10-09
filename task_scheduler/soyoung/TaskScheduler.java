import java.util.*;

class Solution {
  public int leastInterval(char[] tasks, int n) {
    PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder()); // Descending Order.
    int[] taskCount = new int[26]; // count A, B ....
    int oneTime;
    int totalTime = 0;

    for (char c : tasks) {
      taskCount[c - 65]++; // 'A' = 65;
    }
    for (int count : taskCount) {
      if (count > 0)
        q.offer(count);
    }
    while (!q.isEmpty()) {
      oneTime = 0;
      List<Integer> tmpSQ = new ArrayList<>();
      while (oneTime <= n) {
        if (!q.isEmpty()) {
          if (q.peek() > 1) {
            tmpSQ.add(q.poll() - 1);
          } else {
            q.poll();
          }

        }
        totalTime++;
        if (q.isEmpty() && tmpSQ.size() == 0)
          break;
        oneTime++;
      }

      for (int newTask : tmpSQ) {
        q.offer(newTask);
      }
    }
    return totalTime;
  }
}
