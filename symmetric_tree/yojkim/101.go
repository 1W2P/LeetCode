func arrSymChk(arr []int) bool {
	for i := 0; i < len(arr)/2; i++ {
		if arr[i] != arr[len(arr)-1-i] {
			return false
		}
	}
	return true
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	queue := []*TreeNode{root}
	values := make([]int, 0)
	cut := 2
	child := 0
	cur := 0

	for len(queue) > 0 {
		top := queue[0]
		if top.Left != nil {
			queue = append(queue, top.Left)
			values = append(values, top.Left.Val)
			cur++
		} else {
			values = append(values, -1)
		}

		if top.Right != nil {
			queue = append(queue, top.Right)
			values = append(values, top.Right.Val)
			cur++
		} else {
			values = append(values, -1)
		}

		queue = queue[1:]
		child += 2
		if child == cut {
			if !arrSymChk(values) {
				return false
			}
			cut = cur * 2
			cur = 0
			child = 0
			values = make([]int, 0)
		}
	}

	return true
}