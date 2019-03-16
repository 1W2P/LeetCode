package main

import (
	"fmt"
	"sort"
)

type Interval struct {
	Start int
	End   int
}

func main() {
	//Expected [{1 6} {8 10} {15 18}]
	intervals := []Interval{
		Interval{
			Start: 1,
			End:   3,
		},
		Interval{
			Start: 2,
			End:   6,
		},
		Interval{
			Start: 8,
			End:   10,
		},
		Interval{
			Start: 15,
			End:   18,
		},
	}
	fmt.Println(Merge(intervals))


	//Expected [[0,5]]
	intervals2 := []Interval{
		Interval{
			Start: 1,
			End:   4,
		},
		Interval{
			Start: 0,
			End:   2,
		},
		Interval{
			Start: 3,
			End:   5,
		},
	}
	fmt.Println(Merge(intervals2))
	//merge(intervals2)

	lastIntervals := []Interval{
		Interval{
			Start: 2,
			End:   3,
		}, Interval{
			Start: 4,
			End:   5,
		}, Interval{
			Start: 6,
			End:   7,
		}, Interval{
			Start: 8,
			End:   9,
		}, Interval{
			Start: 1,
			End:   10,
		},
	}
	fmt.Println(Merge(lastIntervals))

}

func Merge(intervals []Interval) []Interval {
	var newInterval []Interval

	intervalCount := len(intervals)

	if intervalCount <= 0 {
		return newInterval
	}

	sort.SliceStable(intervals, func(i, j int) bool {
		return intervals[i].Start < intervals[j].Start
	})

	//fmt.Println("sorted : ", intervals)

	newInterval = append(newInterval, intervals[0])
	LAST := 0

	for i := 1; i < intervalCount; i ++ {

		if newInterval[LAST].End < intervals[i].Start {
			newInterval = append(newInterval, intervals[i])
			LAST ++
		} else {
			newInterval[LAST].End = MaxOf(newInterval[LAST].End, intervals[i].End)
		}
	}

	return newInterval
}

func MaxOf(a, b int) int {
	if a > b {
		return a
	}
	return b
}