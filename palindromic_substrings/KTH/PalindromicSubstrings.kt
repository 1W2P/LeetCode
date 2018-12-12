fun main(args:Array<String>){
    println(Solution().countSubstrings("abc"))
}
class Solution {
    companion object {
        val MAX_CNT = 1001
    }
    private val cache = Array(MAX_CNT){ IntArray(MAX_CNT)}
    private lateinit var str:String

    private fun init(){
        for(i in 0 until MAX_CNT)
            for(j in 0 until MAX_CNT)
                cache[i][j] = -1
    }
    private fun check(stx:Int, etx:Int) : Int{
        if(stx >= etx)
            return 1
        if(str[stx] != str[etx])
            return 0
        if(cache[stx][etx] != - 1)
            return cache[stx][etx]
        cache[stx][etx] = check(stx+1, etx-1)
        return cache[stx][etx]
    }
    fun countSubstrings(s: String): Int {
        init()
        str = s
        var ret = 0
        // O(n^2) * O(n/2)
        for(x in 0 until s.length)
            for(y in x until s.length)
                ret += check(x, y)
        return ret
    }
}
