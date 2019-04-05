import Foundation

class Solution {
    var tempS: [Character] = []
    
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        guard s.count > 0 else { return true }
        tempS = Array(s)
        
        for tc in Array(t) {
            guard let sc = tempS.first else { break }
            if sc == tc {
                tempS.removeFirst()
            }
            
            if tempS.count == 0 { return true }
        }
        return false
    }
}
