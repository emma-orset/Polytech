fun factorization(num: Int): Sequence<Int> {
    var remaining = num
    var factor = 2

    return sequence {
        while (remaining > 1) {
            if (remaining % factor == 0) {
                yield(factor)
                remaining /= factor
            } else {
                factor++
            }
        }
    }
}

fun main() {
    while (true) {
        print("Enter a positive integer: ")
        val n = try {
            readLine()?.toInt() ?: 0
        } catch (ex: Exception) { 0 }

        if (n <= 0) {
            println("Exiting...")
            break
        }

        val result = factorization(n).toList()
        println("The prime factorization of $n is $result.")
    }
}
