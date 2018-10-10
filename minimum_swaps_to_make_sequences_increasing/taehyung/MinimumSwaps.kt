fun main(args:Array<String>){
    println(Solution().minSwap(intArrayOf(0,7,8,10,10,11,12,13,19,18), intArrayOf(4,4,5,7,11,14,15,16,17,20)))
}
class Solution{
    val cache = Array(2) {IntArray(10000){-1}}
    val MAX_VALUE = Int.MAX_VALUE - 1
    lateinit var A: IntArray
    lateinit var B: IntArray
    private fun swap(idx:Int){
        A[idx] = B[idx].also { B[idx] = A[idx] }
    }
    private fun solve(isSwapped:Int, idx:Int) : Int{
        //BC1. MAX LENGTH
        if(idx == A.size)
            return 0
        cache[isSwapped][idx].let { if(it != -1) return it}
        var notSwapped = MAX_VALUE
        var swapped =  MAX_VALUE
        for(isSwap in 0..1){
            if(idx == 0 || !(A[idx-1] >= A[idx] || B[idx-1] >= B[idx])){
                solve(isSwap, idx+1).let {
                    if(isSwap == 0)
                        notSwapped = it
                    else
                        swapped = it
                }
            }
            swap(idx)
        }
        println("idx : $idx,  notSwapped : $notSwapped,  swapped : ${swapped+1}")
        cache[isSwapped][idx] = Math.min(notSwapped, swapped + 1)
        return cache[isSwapped][idx]
    }
    fun minSwap(A: IntArray, B: IntArray) :Int{
        this.A = A
        this.B = B
        return solve(0, 0)
    }
}