//
// Created by Gulian Boris on 3/13/23.
//

import Foundation

enum MyError: Error {
    case runtimeError(String)
}

func reverse_str(str: String) -> String {
    var ready_num: String = "";
    for offset in (1...str.count) {
        ready_num.append(str[str.index(str.endIndex, offsetBy: -offset)])
        print(ready_num)
    }
    return ready_num
}

func Straight_str(str: String) -> String {
    var ready_num: String = "";
    for offset in (0...str.count - 1) {
        ready_num.append(str[str.index(str.startIndex, offsetBy: offset)])
        print(ready_num)
    }
    return ready_num
}

func valid_mode(str: String) -> String {
    if (str != "lower" && str != "higher") {
        return "lower"
    }
    return str
}


func valid_num(str: String) throws {
    if let _ = Int(str) {
    } else {
        throw MyError.runtimeError("Cannot covert to num")
    }
}

do {
    let arguments = CommandLine.arguments
    var mode : String
    var str : String
    if CommandLine.arguments.count != 2 {
        throw MyError.runtimeError("Program must get 1 Arg (got \(CommandLine.arguments.count))")
    } else {
        mode = arguments[1]
        str = valid_mode(str: mode);
    }
        let num = readLine()
        try valid_num(str: num ?? "0")
        if (str == "lower") {
            Straight_str(str: num!)
        } else if (str == "higher") {
            reverse_str(str: num!)
        }
} catch MyError.runtimeError(let errorMessage) {
    print(errorMessage)
}

