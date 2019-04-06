package main

import "sort"

func reconstructQueue(people [][]int) [][]int {
	res := people
	sort.Slice(people, func(i, j int) bool {
		if people[i][0] > people[j][0] {return true}
		if people[i][0] == people[j][0] && people[i][1] < people[j][1] {
			return true
		}
		return false
	})//키순으로 정렬

	for i, p := range people {
		j := p[1]
		copy(res[j+1:i+1], res[j:i])
		res[j] = p
	}
	return res
}
