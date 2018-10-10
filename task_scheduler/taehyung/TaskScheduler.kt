import java.util.*
enum class Task{
    TASK, IDLE
}
fun main(args:Array<String>){
    Solution().leastInterval(charArrayOf('A','A','B','B','B','A'),2)
}
class Solution {
    fun leastInterval(tasks: CharArray, n: Int): Int {
        val map = HashMap<Char, Int>()
        for(task in tasks.distinct())
            map[task] = tasks.filter { x-> x == task }.size
        val list = ArrayList<Task>()
        while(map.isNotEmpty()){
            val newTask = ArrayList<Task>()
            for(task in map.entries.sortedByDescending { x->x.value}) {
                newTask.add(Task.TASK)
                task.setValue(task.value-1)
                if(task.value == 0)
                    map.remove(task.key)
                if(newTask.size == n + 1)
                    break
            }
            if(newTask.size < n + 1 && map.isNotEmpty())
                repeat(n +1 - newTask.size) { newTask.add(Task.IDLE)}
            list.addAll(newTask)
        }
        return list.size
    }
}