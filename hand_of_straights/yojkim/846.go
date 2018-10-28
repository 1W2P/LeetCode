import "sort"

func isNStraightHand(hand []int, W int) bool {
	if len(hand)%W != 0 {
		return false
	}

	freqChk := make(map[int]int)
	sort.Ints(hand)

	for _, h := range hand {
		freqChk[h]++
	}

	for len(hand) > 0 {
		val := hand[0]
		for i := 1; i < W; i++ {
			if freqChk[val+i] == 0 {
				return false
			}
		}

		temp := make([]int, 0)
		deleteChk := make(map[int]bool, W)
		for _, h := range hand[1:] {
			isDeleted := false
			for i := 1; i < W; i++ {
				if h == val+i && !deleteChk[i] {
					deleteChk[i] = true
					isDeleted = true
					break
				}
			}
			if !isDeleted {
				temp = append(temp, h)
			}
		}
		hand = temp
	}

	return true
}