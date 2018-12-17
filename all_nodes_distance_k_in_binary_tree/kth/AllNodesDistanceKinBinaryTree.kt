
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143798/1ms-beat-100-simple-Java-dfs-using-hashmap-with-explanation
fun main(args:Array<String>){
    val root  = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left!!.left = TreeNode(6)
    root.left!!.right = TreeNode(2)
    root.left!!.right!!.left = TreeNode(7)
    root.left!!.right!!.right = TreeNode(4)
    root.right!!.left = TreeNode(0)
    root.right!!.right = TreeNode(8)
    val target = root.left!!.left
    val ret = Solution().distanceK(root,target, 2)
    println(ret)
}

class TreeNode(var `val`: Int = 0) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    private val map = hashMapOf<TreeNode, Int>()
    private fun find(root:TreeNode?, target:TreeNode?) : Int{
        root?:let { return -1 }

        if(root == target){
            map[root] = 0
            return 0
        }
        find(root.left, target).let {
            if(it >= 0){
                map[root] = it + 1
                return it + 1
            }
        }
        find(root.right, target).let{
            if(it >= 0){
                map[root] = it + 1
                return it+1
            }
        }
        return -1
    }
    private fun dfs(root : TreeNode?, K:Int, distance:Int, ret:ArrayList<Int>){
        root?:let { return }
        val temp = map.containsKey(root).let {
            if(it)
                map[root]!!
            else
                distance
        }
        if(K == temp)
            ret.add(root.`val`)
        dfs(root.left, K, temp + 1, ret)
        dfs(root.right, K , temp + 1, ret)
    }
    fun distanceK(root: TreeNode?, target: TreeNode?, K: Int): List<Int> {
        find(root, target)
        val ret = ArrayList<Int>()
        dfs(root, K, 0, ret)
        return ret
    }
}