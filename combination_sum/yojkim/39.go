func findComb(prev int, arr []int, target int) [][]int {
	temp := make([][]int, 0)

	if target == 0 {
		list := []int{prev}
		return append(temp, list)
	}

	for _, n := range arr {
		if n >= prev {
			if target-n >= 0 {
				list := findComb(n, arr, target-n)
				for idx, _ := range list {
					temp = append(temp, append([]int{prev}, list[idx]...))
				}
			}
		}
	}

	return temp
}

func combinationSum(candidates []int, target int) [][]int {
	res := make([][]int, 0)

	for _, n := range candidates {
		if target-n >= 0 {
			res = append(res, findComb(n, candidates, target-n)...)
		}
	}

	return res
}