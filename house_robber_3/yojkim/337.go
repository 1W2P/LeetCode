package main

func rob(root *TreeNode) int {
	if root == nil {
		return 0
	}
	sum := root.Val

	if root.Left != nil {
		sum += rob(root.Left.Left) + rob(root.Left.Right)
	}

	if root.Right != nil {
		sum += rob(root.Right.Left) + rob(root.Right.Right)
	}

	childSum := rob(root.Left) + rob(root.Right)
	if sum < childSum {
		return childSum
	} else {
		return sum
	}
}
