import Foundation

class Solution {
    func reconstructQueue(_ people: [[Int]]) -> [[Int]] {
        var resultPeople: [[Int]] = Array.init(repeating: [], count: people.count)
        let sortedPeople = people.sorted {
            $0[0] < $1[0]
        }
        
        for person in sortedPeople {
            var remainCount = person[1]
            for (idx, seat) in resultPeople.enumerated() {
                if seat.count == 0 {
                    if remainCount == 0 {
                        resultPeople[idx] = person
                        break
                    }
                    remainCount -= 1
                } else if seat[0] >= person[0] {
                    remainCount -= 1
                }
            }
        }
        
        return resultPeople
    }
}
