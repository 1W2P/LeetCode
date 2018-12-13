import java.util.*

fun main(args:Array<String>){
    Solution().moveZeroes(intArrayOf(0,1,0,3,12))
}

class Solution {
    fun moveZeroes(nums: IntArray): Unit {
        val ret = ArrayList<Int>(nums.filter { x->x != 0 }.map { x->x }.toList())
        ret.addAll(Array(nums.filter { x-> x == 0 }.size){0})
        for( i in 0 until nums.size)
            nums[i] = ret[i]
    }
}
