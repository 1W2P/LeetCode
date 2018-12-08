package main

import "fmt"

func moveZeroes(nums []int) {
	cur := 0
	mov := 1
	fmt.Println(nums)
	for mov != len(nums) && cur <= mov {
		if nums[cur] == 0 {
			if nums[mov] != 0 {
				temp := append(nums[:cur], nums[mov])
				for i := 0; i < mov-cur; i++ {
					temp = append(temp, 0)
				}
				nums = append(temp, nums[mov+1:]...)
			} else {
				mov++
			}
		} else {
			cur++
			mov++
		}
		fmt.Println("cur : ", cur, "mov : ", mov)
		fmt.Println(nums)
	}
}

func main() {
	moveZeroes([]int{0, 1, 0, 3, 12})
}
