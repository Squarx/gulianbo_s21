protocol ICalculator {
    func circleArea(radius: Double) -> Double

    func fibonacci(n: Int) -> Int

    func fahrenheit(celcius: Double) -> Double
}

class SimpleCalculator: ICalculator {
    func circleArea(radius: Double) -> Double {
        3.14 * radius * radius
    }

    func fibonacci(n: Int) -> Int {
        if n <= 0 {
            return 0
        }
        if n <= 2 {
            return 1
        }
        var first = 1
        var second = 1
        var temp = 0
        for _ in 3...n {
            temp = first + second
            first = second
            second = temp
        }
        return temp
    }

    func fahrenheit(celcius: Double) -> Double {
        celcius * 1.8 + 32
    }
}
