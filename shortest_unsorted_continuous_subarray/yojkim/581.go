func findUnsortedSubarray(nums []int) int {
	head := -1
	tail := -1

	for i := 1; i < len(nums); i++ {
		if nums[i] < nums[i-1] {
			if head == -1 {
				head = i - 1
			}

			if tail < i {
				tail = i
			}

			if nums[i] < nums[head] {
				for j := head - 1; j >= 0; j-- {
					if nums[j] <= nums[i] {
						head = j + 1
						break
					} else if j == 0 {
						head = 0
					}
				}
			}

			for j := tail + 1; j < len(nums); j++ {
				if nums[j] >= nums[i-1] {
					tail = j - 1
					break
				} else if j == len(nums)-1 {
					tail = len(nums) - 1
				}
			}

		}
	}

	if head == -1 {
		return 0
	}

	return tail - head + 1
}