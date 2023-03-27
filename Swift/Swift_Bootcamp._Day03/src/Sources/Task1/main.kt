import kotlin.reflect.KClass
class RevolverDrum<T>(private var type: KClass<*>) {
    var list: ArrayList<T?> = arrayListOf(null, null, null, null, null, null)
    var pointer = 0
    var listSize = 0

    fun add(value: T): Boolean {
        for (i in 0..5) {
            if (list[(i + pointer) % 6] == null) {
                list[(i + pointer) % 6] = value
                listSize++
                pointer = (i + pointer) % 6
                return true
            }
        }
        return false
    }

    fun addAll(inpList: MutableList<T?>): Boolean {
        var size = inpList.size - 1
        var newPointer = 0
        if (size == -1) return false
        var j = 0
        for (i in 0..size) {
            if (list[(i + pointer) % 6] == null) {
                list[(i + pointer) % 6] = inpList[j]
                inpList[j] = null
                j++
                newPointer = (i + pointer) % 6
                listSize++
            }
        }
        pointer = newPointer
        return true
    }

    fun shoot(): T? {
        if (list[pointer] != null) {
            val tmp = list[pointer]
            list[pointer] = null
            pointer++
            listSize--
            return tmp
        }
        return null
    }

    fun unload(): T? {
        val tmp = list[pointer]
        list[pointer] = null
        pointer++
        listSize--
        return tmp
    }

    fun unloadAll(): ArrayList<T?> {
        val tmp = list
        for(i in 0..5) list[i] = null
        return tmp
    }

    fun scroll() {
        pointer = (0..5).random()
    }

    fun size(): Int {
        return listSize
    }

    override fun toString(): String {
//        var type = checkType(list[0])
        var listNow = "["
        for (i in 0..5) {
            if (i != 0) listNow += ", "
            listNow += list[(i + pointer) % 6]
        }
        listNow += "]"
        return "Structure: RevolverDrum<$type>\nObjects: $listNow\nPointer: ${list[pointer]}"
    }

//    private fun checkType(x: Any?): String {
//        return when (x) {
//            is Int -> "Int"
//            is String -> "String"
//            else -> "other"
//        }
//    }

    override fun equals(other: Any?): Boolean {
        var count = 0
        if (other !is RevolverDrum<*>) return false
        if (this.listSize != other.listSize) return false

        for (i in 0..5) {
            for(j in 0..5) {
                if (this.list[i] == other.list[(j + i) % 6]) {
                    count++
                }
                if (count == 6) return true
            }
        }
        return false
    }
}


fun main() {
    val revol = RevolverDrum<Int>(Int::class)
    val a = listOf(null, 2, null, 3, 4, null).toMutableList()
    println("1. Adding elements")
    revol.addAll(a)
//    println(a)
    println(revol)
    revol.add(5)
    println("2. Scroll")
    println(revol)
    revol.scroll()
    println(revol)
    revol.scroll()
    println(revol)
    println("3. Extraction")
    revol.unload()
    println(revol)
    val b = listOf(11, 11, 11, 11, 11, null).toMutableList()
    revol.addAll(b)
    println(revol)
    val c = listOf(11, 11, 3, 4, 5, null).toMutableList()
    println("4. Equals")
    println(revol)
    println(c)
    var result = revol.equals(c)
    println(result)
}