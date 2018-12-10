package main

import "fmt"

func isPalindromic(s string) bool {
	for i:=0; i<len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func countSubstrings(s string) int {
	if len(s) == 0 {
		return 0
	}
	frameSize := 1
	resCnt := 0
	for frameSize <= len(s) {
		idx := 0
		for idx + frameSize <= len(s) {
			if isPalindromic(string(s[idx:idx+frameSize])) {
				resCnt++
			}
			idx++
		}
		frameSize++
	}
	return resCnt
}

func main() {
	fmt.Println(countSubstrings("abc"))
	fmt.Println(countSubstrings("aaa"))
}
