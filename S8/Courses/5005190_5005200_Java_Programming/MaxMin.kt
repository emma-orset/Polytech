fun maxMin(arr: Array<Double>): Pair<Double, Double> {
    val max = arr.maxOrNull() ?: 0.0
    val min = arr.minOrNull() ?: 0.0
    return Pair(max, min)
}

fun main() {
    val a1 = arrayOf(9.0, 8.1, 7.2, 6.3)
    val a2 = arrayOf(1.2, 3.4, 5.6, 2.1, 2.0)
    val a3 = arrayOf(-3.3, -4.4, -2.1, -3.7, -4.2, -1.0)

    val (x1, n1) = maxMin(a1)
    println("The maximum value in a1 is $x1, and the minimum value is $n1")
    val (x2, n2) = maxMin(a2)
    println("The maximum value in a2 is $x2, and the minimum value is $n2")
    val (x3, n3) = maxMin(a3)
    println("The maximum value in a3 is $x3, and the minimum value is $n3")
}
