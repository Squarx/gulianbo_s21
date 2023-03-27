class Revolver<T>: Equatable where T: Equatable {
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


    var bullets: Array<T?> = [T?](repeating: nil, count: 6)
    var pointer = 0
    var listSize = 0

    init(bullets: Array<T?>) {
        var len = bullets.count
        if len > 6 {
            len = 6
        }
        for i in 0..<len {
            self.bullets[i] = bullets[i]
        }
//        if bullets.count > 6 {
//            self.bullets = [bullets[0], bullets[1], bullets[2], bullets[3], bullets[4], bullets[5]]
//        } else {
//            self.bullets = bullets
//        }
    }

    func print_magazine() {
//        var magazine1String = ""
//        for (index, value) in bullets.enumerated() {
//            if let intValue = value {
//                magazine1String += "\(intValue)"
//            } else {
//                magazine1String += "nil"
//            }
//            if index < magazine1.count - 1 {
//                magazine1String += ", "
//            }
//        }
//        print("[\(magazine1String)]")
        var listNow = "["
        for i in 0...5 {
            if (i != 0) {
                listNow += ", "
            }
            if let intValue = bullets[(i + pointer) % 6] {
                listNow += "\(intValue)"
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

    func shoot() -> T? {
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
//                bullets[(index + 6) % 6] = nil
                return res
            } else {
                return nil
            }
        }
        set(newValue) {
            bullets[index] = newValue
        }
    }
//    convenience init() throws {
//        let arr: [T] = Array(repeating: "" as! T, count: 6)
//        try self.init(bullets: arr)
//    }
}

var magazine0 = [1, 2, 3, 4, 5, nil, 7, 8]
var magazine1 = [1, 2, 3, 4, 5, nil]
var magazine2 = ["1", "2", "3", "4", "5", nil]
var magazine3: [Int?] = [nil, nil, nil, nil, nil, nil]
var magazine4 = [nil, 2, nil, 3, 4, nil]
var gun1 = Revolver(bullets: magazine4)
print("Before all")
gun1.print_magazine()
print("1. Adding elements")
gun1.addAll(inpList: magazine1)
gun1.print_magazine()
print("Pointer index, value  = \(gun1.pointer), \(gun1.pointer_value())")
print("2. Subscript")
if let first_val = gun1[0] {
    print("First value = \(first_val)")
} else {
    print("nil")
}
if let last_val = gun1[5] {
    print("Last value = \(last_val)")
} else {
    print("nil")
}
gun1.print_magazine()
print("3. Scroll")
gun1.scroll()

gun1.print_magazine()
print("3. Deletion")
gun1.shoot()
gun1.shoot()
gun1.shoot()
gun1.shoot()
gun1.print_magazine()
print("4. Supply collection")
print("Before")
gun1.print_magazine()
gun1.addAll(inpList: [11, 22, 44, 56, 77, 88])
print("After")
gun1.print_magazine()
print("Pointer index, value  = \(gun1.pointer), \(gun1.pointer_value())")
print("5. Extraction")
var tt = gun1.unloadAll()
gun1.print_magazine()
print("6. Supply collection 2")
gun1.addAll(inpList: [77, 43, 76, 5])
gun1.print_magazine()
print("Pointer index, value  = \(gun1.pointer), \(gun1.pointer_value())")
print("7. Equals")
print("Gun1")
gun1.print_magazine()
var gun2 = Revolver(bullets: [nil, nil, 77, 43, 76, 5])
print("Gun2")
gun2.print_magazine()
if (gun1 == gun2) {
    print("Result: equals")
} else {
    print("Result: not equals")
}
print("Gun1")
gun1.print_magazine()
gun2.unloadAll()
print("Gun2")
gun2.print_magazine()
if (gun1 == gun2) {
    print("Result: equals")
} else {
    print("Result: not equals")
}