func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	res := make([][]int, 0)
	queue := make([]*TreeNode, 0)
	level := 0
	cut := 2
	cnt := 0
	tempArr := []int{root.Val}
	res = append(res, tempArr)
	queue = append(queue, root)
	tempArr = make([]int, 0)
	nextCut := 0

	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if node.Left != nil {
			queue = append(queue, node.Left)
			tempArr = append(tempArr, node.Left.Val)
			nextCut += 2
		}

		if node.Right != nil {
			queue = append(queue, node.Right)
			tempArr = append(tempArr, node.Right.Val)
			nextCut += 2
		}

		cnt += 2

		if cnt == cut && len(tempArr) > 0 {
			res = append(res, tempArr)
			tempArr = make([]int, 0)
			level++
			cut = nextCut
			cnt = 0
			nextCut = 0
		}
	}

	return res
}