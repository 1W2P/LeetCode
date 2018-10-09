package leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * @author manki.kim
 **/
public class TaskScheduler {

	public static void main(String... args) {
		char[] tasks = {'A','A','A'
			,'B', 'B','B'};

		System.out.println(leastInterval(tasks, 2));
	}

	public static int leastInterval(char[] tasks, int n) {
		Queue<Integer> jobs = new PriorityQueue<>();
		Map<Character, Integer> taskIntervalMap = new HashMap<>();

		for (char task : tasks) {
			int taskInterval = taskIntervalMap.getOrDefault(task, 0);
			jobs.add(taskInterval);
			taskIntervalMap.put(task, taskInterval + n + 1);
		}

		int processingTime = 0;
		while (!jobs.isEmpty()) {
			int job = jobs.poll();

			if (job <= processingTime) {
				processingTime++;
			} else {
				processingTime += job - processingTime + 1;
			}

		}

		return processingTime;
	}
}
