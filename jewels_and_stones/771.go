func numJewelsInStones(J string, S string) int {
	jewels := make(map[rune]bool)
	cnt := 0
	for _, j := range J {
		jewels[j] = true
	}
	for _, s := range S {
		if _, ok := jewels[s]; ok {
			cnt++
		}
	}
	return cnt
}