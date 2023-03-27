//
// Created by Gulian Boris on 3/24/23.
//

import Foundation
import XCTest
import Day09
import class Foundation.Bundle
//let fooBinary = productsDirectory.appendingPathComponent("Day09")
class SimpleCalculatorTests: XCTestCase {
    var calculator: SimpleCalculator!

    override func setUp() {
        super.setUp()
        calculator = SimpleCalculator()
    }

    func testCircleArea() {
        let radius = 5.0
        let expectedArea = 3.14 * radius * radius
        let actualArea = calculator.circleArea(radius: radius)
        XCTAssertEqual(actualArea, expectedArea, accuracy: 0.001)
    }

    func testFibonacci() {
        let n = 7
        let expectedValue = 13
        let actualValue = calculator.fibonacci(n: n)
        XCTAssertEqual(actualValue, expectedValue)
    }

    func testFahrenheit() {
        let celcius = 25.0
        let expectedFahrenheit = celcius * 1.8 + 32
        let actualFahrenheit = calculator.fahrenheit(celcius: celcius)
        XCTAssertEqual(actualFahrenheit, expectedFahrenheit, accuracy: 0.001)
    }
}

/// Returns path to the built products directory.
