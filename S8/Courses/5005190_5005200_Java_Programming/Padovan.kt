val padovan = sequence {
    yield(1)
    yield(1)
    yield(1)

    var prevPrev = 1
    var prev = 1
    var current = 1

    while (true) {
        val next = prevPrev + prev
        yield(next)
        prevPrev = prev
        prev = current
        current = next
    }
}

fun main() {
    println(padovan.take(30).toList())
}
