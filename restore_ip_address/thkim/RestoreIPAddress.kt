fun main(args:Array<String>){
    println(Solution().restoreIpAddresses("010010"))
}
class Solution {
    fun restoreIpAddresses(s: String): List<String> {
        val ipList = ArrayList<String>()
        for(first in 1 until 4){
            for(second in 1 until 4){
                for(third in 1 until 4){
                    for(fourth in 1 until 4){
                        if(first+second+third+fourth != s.length)
                            continue
                        try {
                            val octet1 = s.substring(0, first)
                            val octet2 = s.substring(first, first + second)
                            val octet3 = s.substring(first + second, first + second + third)
                            val octet4 = s.substring(first + second + third, first + second + third + fourth)
                            arrayListOf(octet1, octet2, octet3, octet4).let {
                                if(it.any { x-> x.toInt() > 255 || x.length >=2 && x.first() == '0'})
                                    throw Exception("Failed")
                                ipList.add("$octet1.$octet2.$octet3.$octet4")
                            }
                        }catch (e:Exception){
                            println(e.toString())
                        }
                    }
                }
            }
        }
        return ipList
    }
}