class Solution {
    func findOrder(_ numCourses: Int, _ prerequisites: [[Int]]) -> [Int] {
        var queue = [Int]()
        var mat = [[Bool]]()
        var finalCourses = [Int]()
        var thresholds = Array(repeating: 0, count: numCourses)
        var visited = Array(repeating: false, count: numCourses)
        
        for _ in 0..<numCourses {
            var sub = [Bool]()
            for _ in 0..<numCourses {
                sub.append(false)
            }
            mat.append(sub)
        }
        
        let nextCourses = prerequisites.map { item -> Int in
            thresholds[item[0]] += 1
            return item[0] }
        Array(0..<numCourses)
            .filter { !nextCourses.contains($0) }
            .map { queue.append($0) }
        
        prerequisites.forEach { mat[$0[1]][$0[0]] = true }
        while queue.count > 0 {
            guard let first = queue.first else { break }
            if visited[first] {
                queue.removeFirst()
                continue
            }
            if thresholds[first] == 0 {
                mat[first].enumerated().forEach { (idx, item) in
                    if item {
                        queue.append(idx)
                        thresholds[idx] -= 1
                    }
                }
                visited[first] = true
                finalCourses.append(first)
            }
            queue.removeFirst()
            
            if (mat[first].enumerated()
                .filter { $0.element && visited[$0.offset] })
                .count > 0 && queue.count == 0 {
                return []
            }
        }
        return finalCourses.count == numCourses ? finalCourses : []
    }
}
