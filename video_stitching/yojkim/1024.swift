import Foundation

class Solution {
    
    func videoStitching(_ clips: [[Int]], _ T: Int) -> Int {
        var previousClipIndex = -1
        var clipCount = 0
        let cutClips = clips.map { clip -> [Int] in
            var cutClip = clip
            if cutClip[1] > T {
                cutClip[1] = T
            }
            return cutClip
            }.filter { $0[0] <= $0[1] }
        
        var clipIndexesArray = Array.init(repeating: [Int](), count: T + 1)
        
        cutClips.enumerated().forEach { (index, clip) in
            for idx in (clip[0]...clip[1]) {
                clipIndexesArray[idx].append(index)
            }
        }
        
        for (currentIndex, clipIndexes) in clipIndexesArray.enumerated() {
            if clipIndexes.count == 0 { // clip이 채워지지 않은 경우
                return -1
            } else {
                if clipIndexes.contains(previousClipIndex) {
                    continue
                } else {
                    var maxLengthFromCurrentIndex = -1
                    var maxLengthClip = -1
                    clipIndexes.forEach { index in
                        let lengthFromCurrentIndex = cutClips[index][1] - currentIndex
                        if lengthFromCurrentIndex > maxLengthFromCurrentIndex {
                            maxLengthFromCurrentIndex = lengthFromCurrentIndex
                            maxLengthClip = index
                        }
                    }
                    print(cutClips[maxLengthClip])
                    previousClipIndex = maxLengthClip
                    clipCount += 1
                }
            }
        }
        
        return clipCount
    }
}
