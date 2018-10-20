import (
	"strconv"
	"strings"
)

const maxPart = 4

func findValidIP(numStr string, restStr string, partNum int) []string {
	res := make([]string, 0)
	if strings.HasPrefix(numStr, "0") && len(numStr) > 1 {
		return res
	}

	num, _ := strconv.Atoi(numStr)
	if (0 <= num && num <= 255) && len(restStr) <= (maxPart-partNum)*3 {
		if len(restStr) == 0 && partNum == maxPart {
			numStr = "." + numStr
			res = append(res, numStr)
			return res
		}
		nextNumStr := make([]rune, 0)
		validLength := 3
		if len(restStr) < 3 {
			validLength = len(restStr)
		}
		for idx, c := range restStr[:validLength] {
			nextNumStr = append(nextNumStr, c)
			res = append(res, findValidIP(string(nextNumStr), restStr[idx+1:], partNum+1)...)
		}

		for i := 0; i < len(res); i++ {
			if partNum != 1 {
				res[i] = "." + numStr + res[i]
			} else {
				res[i] = numStr + res[i]
			}
		}
	}

	return res
}

func restoreIpAddresses(s string) []string {
	res := make([]string, 0)
	numStr := make([]rune, 0)

	if len(s) < maxPart || len(s) > 3*maxPart {
		return res
	}

	for idx, c := range s[:3] {
		numStr = append(numStr, c)
		res = append(res, findValidIP(string(numStr), s[idx+1:], 1)...)
	}

	return res
}