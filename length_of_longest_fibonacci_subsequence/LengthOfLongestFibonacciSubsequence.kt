fun main(args:Array<String>){
    println(Solution().lenLongestFibSubseq(intArrayOf(1,3,7,11,12,14,18)))
}
class Solution {
    private lateinit var cache:Array<IntArray> // cache[i][j]는 인덱스가 i,j 일 때 최대 피보나치 배열 길이
    private  lateinit var arr:IntArray
    fun solve(stx:Int, etx:Int) : Int{
        if(etx == arr.size || stx == arr.size)
            return 0
        if(cache[stx][etx] != -1)
            return cache[stx][etx]
        var max = 0
        val sum = arr[stx] + arr[etx]
        for(i in etx+1 until arr.size){
            if(arr[i] == sum) {
                max = Math.max(max, solve(etx, i) + 1)
                break
            }
        }
        cache[stx][etx] = max
        return max
    }
    fun lenLongestFibSubseq(A: IntArray): Int {
        arr = A
        cache =  Array(A.size+1) {IntArray(A.size+1){-1}}
        var ret = 0
        for(i in 0 until A.size){
            for(j in i+1 until A.size){
                ret = Math.max(ret, solve(i, j))
            }
        }
        return if(ret != 0) ret +2 else 0
    }
}