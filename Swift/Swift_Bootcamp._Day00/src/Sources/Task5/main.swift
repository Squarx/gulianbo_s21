import Foundation
func input_if(name:String) -> Float? {
    print("Write a value for \(name)")
    var coord : Float?
    if let input = readLine(), let floatInput = Float(input) {
        if ((name == "r1" || name == "r2") && floatInput <= 0) {
            print("Size of \(name) should be more than 0")
            coord = input_if(name:name)
        } else {
            coord = floatInput
        }
    } else {
        print("Couldn't parse a number. Please, try again param = \(name)")
        coord = input_if(name:name)
    }
    return coord
}

var x1 = input_if(name:"x1")!
var y1 = input_if(name:"y1")!
var r1 = input_if(name:"r1")!
var x2 = input_if(name:"x2")!
var y2 = input_if(name:"y2")!
var r2 = input_if(name:"r2")!
get_result(x1: x1, y1: y1, r1: r1, x2: x2, y2: y2, r2: r2)

func get_result(x1 : Float, y1: Float, r1: Float, x2: Float, y2: Float, r2 :Float) {
    let distance = sqrtf(powf(x1-x2, 2) + powf(y1-y2, 2))
    if distance == (r1 + r2) {
        print("Touch")
        let a = (powf(r1, 2.0) - powf(r2, 2.0) + powf(distance, 2.0))/(2.0 * distance)
        let h = sqrtf(powf(r1, 2.0) - powf(a, 2.0))
        let x3 = x1 + a/distance * (x2 - x1)
        let y3 = y1 + a/distance * (y2 - y1)
        let x4 = x3 + h/distance * (y2 - y1)
        let y4 = y3 - h/distance * (x2 - x1)
        print("Touch (\(x4);\(y4))")
    } else if distance > r1 + r2 {
        print("No touch")
    } else if distance < r1 + r2 {
        if distance < abs(r1 - r2) {
            print("One circle is inside another")
        } else {
            print("The circles intersect")
            let a: Float = (powf(r1, 2.0) - powf(r2, 2.0) + powf(distance, 2.0))/(2.0 * distance)
            let h: Float = sqrtf(powf(r1, 2.0) - powf(a, 2.0))
            let x3 = x1 + a/distance * (x2 - x1)
            let y3 = y1 + a/distance * (y2 - y1)
            let x4 = x3 + h/distance * (y2 - y1)
            let y4 = y3 - h/distance * (x2 - x1)
            let x5 = x3 - h/distance * (y2 - y1)
            let y5 = y3 + h/distance * (x2 - x1)
            print("Intersection 1:\n(\(x4);\(y4))\nIntersection 2:\n(\(x5);\(y5))")
        }
    }


}
/*
 0  0  3  4  4  3 -> The circles intersect
 0  0  5  0  0  2 -> One circle is inside another
 0  0  2  4  0  2 -> Touch
 10 10 1  0  0  2 -> No touch
 */
//print(x1!, y1!, r1!, x2!, y2!, r2!)
