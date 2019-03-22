import Foundation

class Solution {
    func findLongestChain(_ pairs: [[Int]]) -> Int {
        var maxChainCount = 0
        let xMin = pairs
            .map { $0[0] }
            .reduce(Int.max) { $0 > $1 ? $1 : $0 }
        let yMax = pairs
            .map { $0[1] }
            .reduce(-1) { $0 < $1 ? $1 : $0 }
        
        let medium = -xMin
        
        // 길이를 구하기 위해 +1
        // yMax 이후 index에서 체크하기 때문에 한번 더 +1
        var chainCnts = Array.init(repeating: 0, count: yMax - xMin + 1 + 1)
        pairs.sorted { $0[0] < $1[0] }
            .map { ($0[0] + medium, $0[1] + medium) }
            .map {
                let (x, y) = $0
                let source = chainCnts[x] + 1
                for target in (y+1..<chainCnts.count) {
                    if chainCnts[target] >= source { break }
                    chainCnts[target] = source
                    if maxChainCount < source {
                        maxChainCount = source
                    }
                }
        }
        
        return maxChainCount
    }
}
