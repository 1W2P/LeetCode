import kotlin.reflect.jvm.internal.impl.load.java.JavaClassesTracker

fun main(args:Array<String>){

}
class TreeNode(var `val`: Int = 0) {
  var left: TreeNode? = null
  var right: TreeNode? = null
}

class Solution {
    fun rob(root: TreeNode?): Int {
        return solve(root, false)
    }
    fun solve(root:TreeNode?, isPreviousRobber:Boolean):Int{
        if(root == null)
            return 0
        var max = 0
        max = if(isPreviousRobber)
            solve(root.left, false ) + solve(root.right, false)
        else{
            val isRobber = solve(root.left,true) + solve(root.right,true) + root.`val`
            val isNotRobber = solve(root.right,false) + solve(root.left , false)
            Math.max(isRobber, isNotRobber)
        }
        return max
    }
}