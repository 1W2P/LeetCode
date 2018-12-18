fun main(args:Array<String>){
    val temp = Solution().lengthOfLongestSubstring(" ")
    println(temp)
}
class Solution {
    fun lengthOfLongestSubstring(s:String) : Int {
        var max = Int.MIN_VALUE
        var start = - 1
        val duplicateMap = HashMap<Char, Int>()
        for (i in 0 until s.length) {
            val ch = s[i]
            (duplicateMap.containsKey(ch) && duplicateMap[ch]!! > start).let {
                if(it)
                    start = duplicateMap[ch]!!
                duplicateMap[ch] = i
                max = Math.max(max, i - start)
            }
        }
        return if(max == Int.MIN_VALUE) 0 else max
    }
}