fun main(args:Array<String>){
    println(Solution().isNStraightHand(intArrayOf(1,2,3,6,2,3,4,7,8), 3))
}
class Solution {
    fun isNStraightHand(hand: IntArray, W: Int): Boolean {
        val orderHand = hand.sorted()
        val hashMap = HashMap<Int, Int>()
        for(num in orderHand){
            if(hashMap.containsKey(num))
                hashMap[num] = hashMap[num]!! + 1
            else
                hashMap[num] = 1
        }
        try {
            while (hashMap.any()) {
                var cnt = 0
                var prevNumber = 0
                val handEntries = hashMap.entries.sortedBy { x->x.key }
                for (i in handEntries) {
                    if (cnt != 0) {
                        if (i.key - prevNumber != 1)
                            throw Exception("Failed")
                    }
                    prevNumber = i.key
                    val nextValue = hashMap[i.key]!! - 1
                    hashMap[i.key] = nextValue
                    if (nextValue == 0)
                        hashMap.remove(i.key)
                    if(++cnt == W) {
                        cnt = 0
                        break
                    }
                }
                if(cnt != 0)
                    throw Exception("Failed")
            }
            return true
        }catch(e:Exception){
            return false
        }
    }
}