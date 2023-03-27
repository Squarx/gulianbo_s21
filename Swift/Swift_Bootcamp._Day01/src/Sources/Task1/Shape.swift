//
// Created by Gulian Boris on 3/15/23.
//

import Foundation

protocol Shape {
    func coorIn(X: Int, Y: Int);
}

class Circle: Shape {
    func coorIn(X: Int, Y: Int) {
        if (Double(r) >= sqrt(pow(Double(x) - Double(X), 2.0) + pow((Double(y) - Double(Y)), 2.0))) {
            var inc: Incident = Incident(shape: "circle")
            print_incedent(incedent: inc)

        } else {
            print("An incident is not in An incident is not in Sovetsky district")
            print("Switch the applicant to the common number: 88008473824")

        }
    }

    func print_incedent(incedent: Incident) {
        switch incedent {
        case .fire(let a, let b, let c), .cat(let a, let b, let c), .leak(let a, let b, let c),.gas(let a, let b, let c):
            print("The incident info:")
            print("\tDescription: \(a)\n\tPhone number: \(b)\n\tType: \(c)")
        case  .notIn(let a, let b, let c):
            print("GG\(a)\n\(b)\n\(c)")
        }
    }

    var x: Int
    var y: Int
    var r: Int

    init(inputString: String) {
        (self.x, self.y, self.r) = (0, 0, 0)
        (self.x, self.y, self.r) = self.pharse_input(inputString: inputString)
    }



    func pharse_input(inputString: String) -> (Int, Int, Int) {
        let components = inputString.components(separatedBy: ";")
        let x = Int(components[0])!
        let secondComponents = components[1].components(separatedBy: " ")
        let y = Int(secondComponents[0])!
        let r = Int(secondComponents[1])!
        return (x, y, r)
    }

}

class Triangle: Shape {
    var x1: Int
    var y1: Int
    var x2: Int
    var y2: Int
    var x3: Int
    var y3: Int
//    var T: Incident

    init(inputString: String) {
        (x1, y1, x2, y2, x3, y3) = (0, 0, 0, 0, 0, 0)
        (x1, y1, x2, y2, x3, y3) = self.pharse_input(inputString: inputString)
    }

    func coorIn(X: Int, Y: Int) {
        let tr1 = (x1 - X) * (y2 - y1) - (x2 - x1) * (y1 - Y)
        let tr2 = (x2 - X) * (y3 - y2) - (x3 - x2) * (y2 - Y)
        let tr3 = (x3 - X) * (y1 - y3) - (x1 - x3) * (y3 - Y)
        if (tr1 >= 0 && tr2 >= 0 && tr3 >= 0 || tr1 <= 0 && tr2 <= 0 && tr3 <= 0) {
            var inc: Incident = Incident(shape: "triangle")
            print_incedent(incedent: inc)

        } else {
            print("An incident is not in An incident is not in Kalinisky district")
            print("Switch the applicant to the common number: 88008473824")

        }
    }

    func print_incedent(incedent: Incident) {
        switch incedent {
        case .fire(let a, let b, let c), .cat(let a, let b, let c), .leak(let a, let b, let c),.gas(let a, let b, let c):
            print("The incident info:")
            print("\tDescription: \(a)\n\tPhone number: \(b)\n\tType: \(c)")
        case  .notIn(let a, let b, let c):
            print("GG\(a)\n\(b)\n\(c)")
        }
    }

    func pharse_input(inputString: String) -> (Int, Int, Int, Int, Int, Int) {
        let components = inputString.components(separatedBy: " ")
        let firstComponents = components[0].components(separatedBy: ";")
        let x1 = Int(firstComponents[0])! // 1
        let y1 = Int(firstComponents[1])! // 2
        let secondComponents = components[1].components(separatedBy: ";")
        let x2 = Int(secondComponents[0])! // 3
        let y2 = Int(secondComponents[1])! // 4
        let thirdComponents = components[2].components(separatedBy: ";")
        let x3 = Int(thirdComponents[0])!// 5
        let y3 = Int(thirdComponents[1])! // 6
        return (x1, y1, x2, y2, x3, y3)
    }
}

class Tetragon: Shape {
    var x1: Int
    var y1: Int
    var x2: Int
    var y2: Int
    var x3: Int
    var y3: Int
    var x4: Int
    var y4: Int

    init(inputString: String) {
        (x1, y1, x2, y2, x3, y3, x4, y4) = (0, 0, 0, 0, 0, 0, 0, 0)
        (x1, y1, x2, y2, x3, y3, x4, y4) = self.pharse_input(inputString: inputString)
    }


    func pharse_input(inputString: String) -> (Int, Int, Int, Int, Int, Int, Int, Int) {
        let components = inputString.components(separatedBy: " ")
        let firstComponents = components[0].components(separatedBy: ";")
        let x1 = Int(firstComponents[0])! // 1
        let y1 = Int(firstComponents[1])! // 2
        let secondComponents = components[1].components(separatedBy: ";")
        let x2 = Int(secondComponents[0])! // 3
        let y2 = Int(secondComponents[1])! // 4
        let thirdComponents = components[2].components(separatedBy: ";")
        let x3 = Int(thirdComponents[0])!// 5
        let y3 = Int(thirdComponents[1])! // 6
        let fourthComponents = components[3].components(separatedBy: ";")
        let x4 = Int(fourthComponents[0])!// 7
        let y4 = Int(fourthComponents[1])!// 8
        return (x1, y1, x2, y2, x3, y3, x4, y4)
    }


    func coorIn(X: Int, Y: Int) {
        let tr1 = (x1 - X) * (y2 - y1) - (x2 - x1) * (y1 - Y)
        let tr2 = (x2 - X) * (y3 - y2) - (x3 - x2) * (y2 - Y)
        let tr3 = (x3 - X) * (y1 - y3) - (x1 - x3) * (y3 - Y)

        let tr4 = (x3 - X) * (y4 - y3) - (x4 - x3) * (y3 - Y)
        let tr5 = (x4 - X) * (y1 - y4) - (x1 - x4) * (y4 - Y)
        let tr6 = (x1 - X) * (y3 - y1) - (x3 - x1) * (y1 - Y)
        if ((tr1 >= 0 && tr2 >= 0 && tr3 >= 0 || tr1 <= 0 && tr2 <= 0 && tr3 <= 0) && (tr4 >= 0 && tr5 >= 0 && tr6 >= 0 || tr4 <= 0 && tr5 <= 0 && tr6 <= 0)) {
            var inc: Incident = Incident(shape: "tetragon")
            print_incedent(incedent: inc)

        } else {
            print("An incident is not in An incident is not in Kirovsky district")
            print("Switch the applicant to the common number: 88008473824")

        }
    }

    func print_incedent(incedent: Incident) {
        switch incedent {
        case .fire(let a, let b, let c), .cat(let a, let b, let c), .leak(let a, let b, let c),.gas(let a, let b, let c):
            print("The incident info:")
            print("\tDescription: \(a)\n\tPhone number: \(b)\n\tType: \(c)")
        case  .notIn(let a, let b, let c):
            print("GG\(a)\n\(b)\n\(c)")
        }
    }
}

