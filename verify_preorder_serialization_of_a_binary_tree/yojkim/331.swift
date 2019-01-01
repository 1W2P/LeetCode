class Solution {
    func validateTree(_ treeValues: [String], idx: Int) -> Int {
        if treeValues.count <= idx {
            return -1
        }
        var currentIdx = idx
        switch treeValues[idx] {
        case "#":
            return currentIdx+1
        default:
            currentIdx = validateTree(treeValues, idx: currentIdx+1)
            if currentIdx == -1 { return -1 }
            currentIdx = validateTree(treeValues, idx: currentIdx)
            return currentIdx
        }
    }
    
    func isValidSerialization(_ preorder: String) -> Bool {
        let treeValues = preorder.split(separator: ",").map { String($0) }
        return validateTree(treeValues, idx: 0) != treeValues.count ? false : true
    }
}
