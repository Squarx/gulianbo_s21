import Foundation


print("Enter zone parameters:")
var coord_zone = readLine()!
do {
    let T: Zone = try Zone(coord_zone)
    T.printer_zone_info()
    print("Enter an incident coordinates:")
    let coord_in = readLine()!
    let (x, y) = try pharse_input(inputString: coord_in)
    T.place?.coorIn(X: x, Y: y)
} catch MyError.runtimeError(let errorMessage) {
    print(errorMessage)
}




func pharse_input(inputString: String) throws -> (Int, Int) {
    let pattern_input = "^-?[0-9]+;-?[0-9]+$"
    let range = NSRange(location: 0, length: inputString.utf16.count)
    let regex = try! NSRegularExpression(pattern: pattern_input)
    if (regex.firstMatch(in: inputString, options: [], range: range) != nil) {
        let components = inputString.components(separatedBy: ";")
        let x = Int(components[0])!
        let y = Int(components[1])!
        return (x, y)
    } else {
        throw MyError.runtimeError("CAnnot convert coordinates")
    }
}
enum MyError: Error {
    case runtimeError(String)
}


/**

 - Parameter input:
 - Returns: (0 - NO match || 1 - circle || 2 - rectangle || 3 - tetragon(square))
 */
func resolve_shape(input: String) -> Int {
    var shape = 0
    let pattern_circle = "^-?[0-9]+;-?[0-9]+ [0-9]+$"
    let pattern_rect = "^(-?[0-9]+;-?[0-9]+ ){2}-?[0-9]+;-?[0-9]+$"
    let pattern_square = "^(-?[0-9]+;-?[0-9]+ ){3}-?[0-9]+;-?[0-9]+$"
    let range = NSRange(location: 0, length: input.utf16.count)
    let regex_c = try! NSRegularExpression(pattern: pattern_circle)
    let regex_r = try! NSRegularExpression(pattern: pattern_rect)
    let regex_s = try! NSRegularExpression(pattern: pattern_square)
    if (regex_c.firstMatch(in: input, options: [], range: range) != nil) {
        shape = 1
    }
    if (regex_r.firstMatch(in: input, options: [], range: range) != nil) {
        shape = 2
    }
    if (regex_s.firstMatch(in: input, options: [], range: range) != nil) {
        shape = 3
    }
    return shape
}



enum Incident{
    case fire( description : String ,num : String , type: String)
    case gas(description: String,num: String, type: String)
    case leak(description: String,num: String, type: String)
    case cat(description: String,num: String, type: String)
    case notIn(description: String,num: String, type: String)
    init(shape: String) {
        if shape == "circle" {
            self = .fire(description :"The house on fire", num : "+74832648573", type: "Fire")
        } else if shape == "triangle"{
            self = .gas(description: "Aboba", num: "+74832648573", type: "Gas")
        } else {
            self = .cat(description: "the woman said her cat can't get off the tree", num: "+74832648573", type: "cat on the tree")
        }
    }

}