var parentMap map[*TreeNode]*TreeNode
var visitChk map[*TreeNode]bool
var res []int

func findParents(node *TreeNode) {
	if node.Left != nil {
		parentMap[node.Left] = node
		findParents(node.Left)
	}

	if node.Right != nil {
		parentMap[node.Right] = node
		findParents(node.Right)
	}
}

func findkDistanceNode(node *TreeNode, dis int) {
	visitChk[node] = true
	if dis == 0 {
		res = append(res, node.Val)
		return
	}

	if node.Left != nil && !visitChk[node.Left] {
		findkDistanceNode(node.Left, dis-1)
	}

	if node.Right != nil && !visitChk[node.Right] {
		findkDistanceNode(node.Right, dis-1)
	}

	if parentMap[node] != nil && !visitChk[parentMap[node]] {
		findkDistanceNode(parentMap[node], dis-1)
	}
}

func distanceK(root *TreeNode, target *TreeNode, K int) []int {
	res = make([]int, 0)
	if root == nil || target == nil {
		return res
	}
	parentMap = make(map[*TreeNode]*TreeNode)
	visitChk = make(map[*TreeNode]bool)
	findParents(root)
	findkDistanceNode(target, K)
	return res

}