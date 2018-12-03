package main

import "fmt"

func subarrayBitwiseORs(A []int) int {
	prev := map[int]bool {A[len(A)-1]: true}
	res := map[int]bool {A[len(A)-1]: true}

	for i:=len(A)-2; i>=0; i-- {
		res[A[i]] = true
		temp := map[int]bool{A[i]:true}
		for n, _ := range prev {
			res[A[i] | n] = true
			temp[A[i] | n] = true
		}
		prev = temp
	}
	return len(res)
}

func main() {
	fmt.Println(subarrayBitwiseORs([]int{1, 2, 4}))
}