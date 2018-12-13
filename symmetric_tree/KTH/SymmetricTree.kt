import java.util.*
import kotlin.math.log2

fun main(args:Array<String>){
    val root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left?.let {
       it.left = TreeNode(3)
        it.right = TreeNode(4)
    }
    root.right?.let {
        it.left = TreeNode(4)
        it.right = TreeNode(3)
    }
    Solution().isSymmetric(root)
}
  class TreeNode(var `val`: Int = 0) {
      var left: TreeNode? = null
     var right: TreeNode? = null
 }

class Solution {
    fun isSymmetric(root: TreeNode?): Boolean {
        if(root == null)
            return true
        val list = ArrayList<ArrayList<Int?>>()
        bfs(root, list)
        if(list.size == 1)
            return true
        for( i in list){
            for(j in 0 until i.size){
                if(i[j] != i[i.size -1 -j] )
                    return false
            }
        }
        return true
    }
    private fun bfs(root : TreeNode?, list:ArrayList<ArrayList<Int?>>)
    {
        root?.let {
            val q = ArrayList<TreeNode?>()
            var secQ:Queue<TreeNode?>
            q.add(it)
            while(q.any()){
                secQ = LinkedList(q)
                q.clear()
                list.add(ArrayList())
                while(secQ.any()){
                    val node = secQ.poll()
                    list.last().add(node?.`val`)
                    node?.let {
                        q.add(it.left)
                        q.add(it.right)
                    }
                }
            }
        }
    }
}
