type TaskGroup struct {
	task string
	cnt  int
}

type TaskGroups []TaskGroup

func (tg TaskGroups) Len() int           { return len(tg) }
func (tg TaskGroups) Swap(i, j int)      { tg[i], tg[j] = tg[j], tg[i] }
func (tg TaskGroups) Less(i, j int) bool { return tg[i].cnt > tg[j].cnt }

func sortByCnt(tasks []byte) TaskGroups {
	taskCnt := make(map[byte]int)
	taskGroups := make(TaskGroups, 0)

	for _, t := range tasks {
		taskCnt[t]++
	}

	for t, cnt := range taskCnt {
		taskGroups = append(taskGroups, TaskGroup{
			task: string(t),
			cnt:  cnt,
		})
	}

	sort.Sort(taskGroups)
	return taskGroups
}

func leastInterval(tasks []byte, n int) int {
	taskGroups := sortByCnt(tasks)

	restTaskCnt := 0
	topTaskType := 1
	topCnt := taskGroups[0].cnt
	for i := 1; i < len(taskGroups); i++ {
		if topCnt == taskGroups[i].cnt {
			topTaskType++
		} else {
			restTaskCnt = restTaskCnt + taskGroups[i].cnt
		}
	}

	blankCnt := n - (topTaskType - 1)
	if blankCnt < 0 {
		blankCnt = 0
	}
	blankCnt = blankCnt * (topCnt - 1)
	schedulerCnt := topTaskType*topCnt + blankCnt
	if blankCnt < restTaskCnt {
		return len(tasks)
	} else {
		return schedulerCnt
	}
}