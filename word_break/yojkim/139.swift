import Foundation

class Solution {
    private var checkIdx: [String: Bool] = [:]

    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        guard s.count > 0, wordDict.count > 0 else { return false }
        guard checkIdx[s] == nil else { return false }
        for word in wordDict {
            if s.hasPrefix(word) {
                if s.count == word.count { return true }
                let endIdx = s.index(s.startIndex, offsetBy: word.count)
                if wordBreak(String(s[endIdx...]), wordDict) { return true }
            }
        }
        self.checkIdx[s] = true
        return false
    }
}
