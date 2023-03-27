//
// Created by Gulian Boris on 3/17/23.
//

import Foundation

enum MyError: Error {
    case invalidInput(name: String)
    case invalidBulletType(name: String)
//    case outOfAmmo
//    case jammed
//    case gunLocked
}

class Revolver<T: Bullet>: Equatable where T: Equatable {
    var bullets: Array<T?> = [T?](repeating: nil, count: 6)
    var pointer = 0
    var listSize = 0

    init(bullets: Array<T?>) throws {
        var len = bullets.count
        if !self.validate_input(bullets: bullets) {
            throw MyError.invalidInput(name: "Invalid input")
        }
        if !self.validate_input1(bullets: bullets) {
            throw MyError.invalidInput(name: "Already in list")
        }
        if len > 6 {
            len = 6
        }
        for i in 0..<len {

            if bullets[i]?.alreadyGet == false {
                self.bullets[i] = bullets[i]
                bullets[i]?.ready()
            }

//            self.bullets[i]?.alreadyGet = true
        }
    }

    func validate_input1(bullets: Array<T?>) -> Bool {
        for newBullet in bullets {
            for oldBullet in self.bullets {
                if oldBullet != nil {
                    if oldBullet?.id == newBullet?.id {
                        return false
                    }
                }
            }
        }
        return true
    }

    func validateBulletId(bullets: T?) -> Bool {
        if bullets?.alreadyGet == true {
            return false
        }
        for oldBullet in self.bullets {
            if oldBullet != nil {
                if oldBullet?.id == bullets?.id {
                    return false
                }
            }
        }
        return true
    }

    func noAmmo() -> Bool {
        for i in self.bullets {
            if i != nil {
                return false
            }
        }
        return true
    }

    func addBullet(_ newBullet: T?) throws -> Bool where T: Bullet {
        if newBullet?.alreadyGet == true {
            return false
        }
        if noAmmo() {
            if newBullet != nil {
                add(value: newBullet!)
                return true
            } else {
                return false
            }

        } else {
            for i in bullets {
                if i != nil {
                    if type(of: i) != type(of: newBullet) || !validateBulletId(bullets: newBullet) || newBullet?.alreadyGet == true{
//                        print(type(of: i), type(of: newBullet))
//                        throw MyError.invalidBulletType(name: "Class or Bullet does not suit")
                        return false
                    }
                }
            }
            if newBullet != nil {
                add(value: newBullet!)
                return true
            } else {
                return false
            }
            return true
        }
    }


    static func ==(lhs: Revolver<T>, rhs: Revolver<T>) -> Bool {
        if lhs.bullets.count != rhs.bullets.count {
            return false
        }
        for i in 0..<lhs.bullets.count {
            if lhs.bullets == rhs.bullets || lhs.bullets == rhs.bullets.reversed() {
                return true
            }
            rhs.bullets.append(rhs.bullets.removeFirst())
        }
        return false
    }


    func validate_input(bullets: [T?]) -> Bool {
        var validate: [String] = []
        for bullet in bullets {
//            print(String(describing: type(of: bullet)))
            if let bullet = bullet {
                let bulletType = String(describing: type(of: bullet))
                if validate.count == 0 {
                    validate.append(bulletType)
                } else {
                    if !validate.contains(bulletType) {
                        return false
                    }
                }
            }
        }
        return true
    }

    func print_magazine() {

        var listNow = "["
        for i in 0...5 {
            if (i != 0) {
                listNow += ", "
            }
            if let intValue = bullets[(i + pointer) % 6] {
                listNow += "\(intValue.id)"
            } else {
                listNow += "nil"
            }
//            listNow += "\(bullets[(i + pointer) % 6])"
        }
        listNow += "]"
//        print(listNow)
        print("Structure: RevolverDrum<\(type(of: self.bullets[0]))>\nObjects: \(listNow)\nPointer: index = \(pointer) value = \(self.pointer_value())")
//        self.pointer_value()
    }

    func add(value: T) -> Bool {
        for i in 0...5 {
            if (bullets[(i + pointer) % 6] == nil) {
                bullets[(i + pointer) % 6] = value
                listSize += 1
                pointer = (i + pointer) % 6
                value.ready()
                return true
            }
        }
        return false
    }

    func addAll(inpList: Array<T?>) -> Bool {
        var size = inpList.count - 1
        var newPointer = 0
        if (size == -1) {
            return false
        }
        var j = 0
        for i in 0...size {
            if (bullets[(i + pointer) % 6] == nil) {
                bullets[(i + pointer) % 6] = inpList[j]
//                inpList[j] = nil
                j += 1
                newPointer = (i + pointer) % 6
                listSize += 1
            }
        }
        pointer = newPointer
        return true
    }

    func delete() -> T? {
        if (bullets[pointer] != nil) {
            let tmp = bullets[pointer]
            bullets[pointer] = nil
            pointer = (pointer + 1 + 6) % 6
            listSize -= 1
            return tmp
        }
        pointer = (pointer + 1 + 6) % 6
        return nil
    }

    func unload() -> T? {
        let tmp = bullets[pointer]
        bullets[pointer] = nil
        pointer = (pointer + 1 + 6) % 6
        listSize -= 1
        return tmp
    }

    func unloadAll() -> Array<T?> {
        let tmp: Array<T?> = bullets
        for i in 0...5 {
            bullets[i] = nil
        }
        pointer = 0
        return tmp
    }

    func scroll() {
        pointer = Int.random(in: 0...5)
//        (bullets[0], bullets[1], bullets[2], bullets[3], bullets[4], bullets[5]) = (bullets[(0 + pointer) % 6], bullets[(1 + pointer) % 6], bullets[(2 + pointer) % 6], bullets[(3 + pointer) % 6], bullets[(4 + pointer) % 6], bullets[(5 + pointer) % 6])
//        pointer = 0
    }

    func size() -> Int {
        bullets.count
    }

    func pointer_value() -> String {
        if let res = bullets[pointer] {
            return "\(res)"
        } else {
            return "nil"
        }
    }

    subscript(index: Int) -> T? {
        get {
            if index >= 0 {
                var res = bullets[(index + 6) % 6]
                bullets[(index + 6) % 6] = nil
                return res
            } else {
                return nil
            }
        }
        set(newValue) {
            bullets[index] = newValue
        }
    }

    func shoot() {
        let value = bullets[pointer]
        if value != nil && (value?.isLoaded == true) {
            print("A shot one")
            value?.shoot()

        } else {
            if value?.isLoaded == false {
                print("A damp one")
            }
            print("Click")
        }
        delete()
    }

}
