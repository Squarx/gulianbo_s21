//
// Created by Gulian Boris on 3/14/23.
//

import Foundation

do {
    let code = try validInt()
    let response = Response(statusCode: code)
    print_message(message: response)
} catch MyError.runtimeError(let errorMessage) {
    print(errorMessage)
}


func validInt() throws -> Int {
    let str = readLine()!
    if let _ = Int(str) {
    } else {
        throw MyError.runtimeError("Cannot covert to num")
    }
    return Int(str)!
}

func print_message(message: Response) {
    switch message {
    case .success(let message, let code):
        print("Code: \(code)\n\(message)")
    case .error(let name, let code, let title, let description):
        print("\(name):\n\tCode: \(code)\n\tTitle: \(title)\n\tDescriprion: \(description)")
    case .undefined(let code, let description):
        print("Error code: \(code)\n\t\(description)")
    }
}

enum MyError: Error {
    case runtimeError(String)
}

class Message {

    init(name: String?, code: Int, title: String?, description: String) {
        self.name = name
        self.code = code
        self.title = title
        self.description = description
    }

    var name: String?
    var code: Int
    var title: String?
    var description: String

    func print_info() {
        print(name ?? "")
        print("\tCode: ", code)
        print("\ttitle:" + (title ?? ""))
        print("\tDescription:" + description)
    }
}

enum Response {
    case success(message: String, code: Int)
    case error(name: String, code: Int, title: String, description: String)
    case undefined(code: Int, description: String)

    init(statusCode: Int) {
        if statusCode >= 200 && statusCode <= 201 {
            self = .success(message: "The request processed successfully", code: statusCode)
        } else {
            if (statusCode == 1000) {
                self = .error(name: "UndefinedUserError", code: statusCode, title: "User not defined ", description: "he user is not identified. Try later.")
            } else if (statusCode == 1001) {
                self = .error(name: "ExpiredSessionError", code: statusCode, title: "Session have expired", description: "The session is expired")
            } else if (statusCode == 1002) {
                self = .error(name: "NoConnectError", code: statusCode, title: "No connetion", description: "No connection.  Try later.")
            } else if (statusCode == 1003) {
                self = .error(name: "NoConnectionError", code: statusCode, title: "No connection", description: "There is no internet connection. Try later.")
            } else {
                self = .undefined(code: statusCode, description: "Unknown error. Please, try again later")
            }
        }
    }
}