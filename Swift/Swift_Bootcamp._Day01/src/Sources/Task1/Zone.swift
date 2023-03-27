//
// Created by Gulian Boris on 3/15/23.
//

import Foundation

class Zone {
    var shape: String
    var phoneNum: String
    var name: String
    var dept: Int
    var lvl: String
    var place: Shape?
    func printer_zone_info() {
        print("The zone info:")
        print("\tThe shape of area: \(shape)")
        print("\tPhone number: \(phoneNum)")
        print("\tName: \(name)")
        print("\tEmergency dept: \(dept)")
        print("\tDanger level: \(lvl)")
    }
    func print_incedent_info(X: Int, Y: Int) {
        place?.coorIn(X: X, Y: Y)
    }
    init(_ inputStr: String) throws {
        switch (resolve_shape(input: inputStr)) {
        case 1:
            self.shape = "Circle"
            self.phoneNum = Phones.circle.rawValue
            self.name = Names.circle.rawValue
            self.dept = Dept.circle.rawValue
            self.lvl = Level.circle.rawValue
            place = Circle(inputString: inputStr)

        case 2:
            self.shape = "Triangle"
            self.phoneNum = Phones.triangle.rawValue
            self.name = Names.triangle.rawValue
            self.dept = Dept.triangle.rawValue
            self.lvl = Level.triangle.rawValue
            place = Triangle(inputString: inputStr)

        case 3:
            self.shape = "Tetragon"
            self.phoneNum = Phones.tetragon.rawValue
            self.name = Names.tetragon.rawValue
            self.dept = Dept.tetragon.rawValue
            self.lvl = Level.tetragon.rawValue
            place = Tetragon(inputString: inputStr)

        default:
            throw MyError.runtimeError("Cannot convert coordinates")
        }


        enum Phones: String {
            case circle = "+78007562545"
            case triangle = "89007562556"
            case tetragon = "79007562378"
            case common = "23123123123123"

        }

        enum Names: String {
            case circle = "Sovetsky district"
            case triangle = "Kalinisky district"
            case tetragon = "Kirovsky district"
            case common = "Undefined"
        }

        enum Dept: Int {
            case circle = 49324
            case triangle = 50234
            case tetragon = 12394
            case common = 0000
        }

        enum Level: String {
            case circle = "Low"
            case triangle = "Medium"
            case tetragon = "High"
            case common = "Undefined"
        }
    }

}
