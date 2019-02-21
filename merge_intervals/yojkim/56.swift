import Foundation

public class Interval {
    var start: Int
    var end: Int
    
    init(_ start: Int, _ end: Int) {
        self.start = start
        self.end = end
    }
}

class Solution {
    func checkOverlaps(first: Interval, second: Interval) -> Bool {
        if first.end >= second.start {
            return true
        }
        return false
    }
    
    func merge(_ intervals: [Interval]) -> [Interval] {
        guard intervals.count > 0 else { return [] }
        var results: [Interval] = []
        var sortedIntervals = intervals.sorted { $0.start < $1.start }
        var first = sortedIntervals.removeFirst()
        
        while sortedIntervals.count > 0 {
            let next = sortedIntervals.removeFirst()
            if checkOverlaps(first: first, second: next) {
                first = Interval(
                    first.start <= next.start
                        ? first.start : next.start,
                    first.end >= next.end
                        ? first.end : next.end)
            } else {
                results.append(first)
                first = next
            }
        }
        
        results.append(first)
        return results
    }
}
