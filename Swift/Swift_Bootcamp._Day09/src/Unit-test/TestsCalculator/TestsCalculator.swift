//
//  BullsEyeTests.swift
//  BullsEyeTests
//
//  Created by Gulian Boris on 3/25/23.
//

import XCTest
@testable import UnitTest
class BullsEyeTests: XCTestCase {
    var sut: SimpleCalculator!
    override func setUpWithError() throws {
        try super.setUpWithError()
        sut = SimpleCalculator()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }

    override func tearDownWithError() throws {
        sut = nil
        try super.tearDownWithError()
        // Put teardown code here. This method is called after the invocation of each test method in the class.
    }

   
    func testCircleArea() {
           let radius = 5.0
           let expectedArea = 78.5
           let actualArea = sut.circleArea(radius: radius)
           XCTAssertEqual(actualArea, expectedArea, accuracy: 0.01)
       }
       
       func testFibonacci() {
           let input = 10
           let expectedOutput = 55
           let actualOutput = sut.fibonacci(n: input)
           XCTAssertEqual(actualOutput, expectedOutput)
       }
       
       func testFahrenheit() {
           let celcius = 20.0
           let expectedFahrenheit = 68.0
           let actualFahrenheit = sut.fahrenheit(celcius: celcius)
           XCTAssertEqual(actualFahrenheit, expectedFahrenheit, accuracy: 0.01)
       }

//    func testPerformanceExample() throws {
//        // This is an example of a performance test case.
//        measure {
//            // Put the code you want to measure the time of here.
//        }
//    }

}
