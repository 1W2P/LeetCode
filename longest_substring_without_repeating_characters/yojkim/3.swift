class Solution {
    var maxLen = 0
    var frame: String = ""
    func lengthOfLongestSubstring(_ s: String) -> Int {
        for c in s {
            var isOk = true
            var idx = 0
            for val in frame {
                if c == val {
                    isOk = false
                    break
                }
                idx += 1
            }
            if !isOk {
                frame.removeFirst(idx+1)
            }
            frame.append(c)
            if frame.count > maxLen {
                maxLen = frame.count
            }
        }
        return maxLen
    }
}