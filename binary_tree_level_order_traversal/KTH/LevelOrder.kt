import java.util.*
import kotlin.reflect.jvm.internal.impl.load.java.JavaClassesTracker

fun main(args:Array<String>){
    val root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right!!.left = TreeNode(15)
    root.right!!.right = TreeNode(7)
    Solution().levelOrder(root)
}
class TreeNode(var `val`: Int = 0) {
  var left: TreeNode? = null
  var right: TreeNode? = null
}

class Solution {
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        return BFS(root)
    }
    fun BFS(root:TreeNode?) : List<List<Int>>{
        val ret = ArrayList<ArrayList<Int>>()
        val list = ArrayList<TreeNode>()
        if(root == null)
            return ret
        root.left?.let {
            list.add(it)
        }
        root.right?.let {
            list.add(it)
        }
        ret.add(arrayListOf(root.`val`))
        while(list.any()){
            val list2 = list.toList()
            list.clear()
            ret.add(arrayListOf())
            for(temp in list2){
                ret.last().add(temp.`val`)
                temp.left?.let {
                    list.add(it)
                }
                temp.right?.let {
                    list.add(it)
                }
            }
        }
        return ret
    }
}