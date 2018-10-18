func lenLongestFibSubseq(A []int) int {
	chk := make(map[int]bool)
	max, cnt := 0, 2

	for i := 0; i < len(A); i++ {
		chk[A[i]] = true
	}

	for i := 0; i < len(A)-1; i++ {
		for j := i + 1; j < len(A); j++ {
			x, y := A[i], A[j]
			for chk[x+y] {
				cnt++
				x, y = y, x+y
			}
			if cnt > max {
				max = cnt
			}
			cnt = 2
		}
	}

	if max > 2 {
		return max
	}
	return 0
}