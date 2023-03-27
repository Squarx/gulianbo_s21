import Foundation
protocol Bullet : Equatable {
    var isLoaded: Bool { get }
    var id: UUID { get }
    var alreadyGet: Bool {get}
    func shoot()
    func ready();
}


class TwentyTwo : Bullet {
    func ready() {
        self.alreadyGet = true
    }

    static func == (lhs: TwentyTwo, rhs: TwentyTwo) -> Bool {
        lhs.isLoaded == rhs.isLoaded && lhs.id == rhs.id
    }

    var isLoaded: Bool = Bool.random()
    var alreadyGet: Bool = false
    var id: UUID

    func shoot() {
        print("Bang")
        print("Info:\n\tId = \(id)  Calibre = 22, isLoaded  = \(isLoaded)")
    }
    init() {
        self.id = UUID()
    }
}

class ThreeEighty :Bullet {
    static func == (lhs: ThreeEighty, rhs: ThreeEighty) -> Bool {
        lhs.isLoaded == rhs.isLoaded && lhs.id == rhs.id
    }
    func ready() {
        self.alreadyGet = true
    }
    var isLoaded: Bool = Bool.random()
    var alreadyGet: Bool = false
    var id: UUID

    func shoot() {
        print("Bang - Bang")
        print("Info:\n\tId = \(id)  Calibre = 38, isLoaded  = \(isLoaded)")    }
    init() {
        self.id = UUID()
    }

}
class FortyFive :Bullet {
    static func == (lhs: FortyFive, rhs: FortyFive) -> Bool {
        lhs.isLoaded == rhs.isLoaded && lhs.id == rhs.id
    }
    func ready() {
        self.alreadyGet = true
    }
    var isLoaded: Bool = Bool.random()

    var id: UUID
    var alreadyGet: Bool = false
    func shoot() {
        print("BANG-BANG-BANG")
        print("Info:\n\tId = \(id)  Calibre = 45, isLoaded  = \(isLoaded)")
    }
    init() {
        self.id = UUID()
    }

}


var Tw0 = TwentyTwo()
var Tw1 = TwentyTwo()
var Tw2 = TwentyTwo()
var Tw3 = TwentyTwo()
var Tw:[TwentyTwo] = [Tw3, Tw1, Tw2]
var TwNil:[TwentyTwo?] = [nil, nil, nil]
do {
    var mainGun = try Revolver(bullets: TwNil)
//    mainGun.print_magazine()
    try mainGun.addBullet(Tw0)
    print("Try again add same bullet")
    mainGun.print_magazine()
    try mainGun.addBullet(Tw0)
    print("After")
    mainGun.print_magazine()
    print("Add Collection")
    mainGun.addAll(inpList: Tw)
    mainGun.print_magazine()
    print("Shooting")
    mainGun.shoot()
    mainGun.shoot()
    mainGun.shoot()
    mainGun.shoot()
    mainGun.shoot()
    mainGun.shoot()
    print("Empty magazine")
    mainGun.print_magazine()
    print("Try to add already used AMMO")
    var secGun = try Revolver(bullets: TwNil)
    try print("Result = \(secGun.addBullet(Tw0))")
    var Fv0 = FortyFive()
    var Fv1 = FortyFive()
    var Fv2 = FortyFive()
    var Fv3 = FortyFive()
    var Fv4 = FortyFive()
    var Fv01:[FortyFive] = [Fv0, Fv1, Fv2]
    var Fv02:[FortyFive] = [Fv0, Fv3, Fv4]
    print("Same bullet in different collections")
    var gun3 = try Revolver(bullets: Fv01)
    var gun4 = try Revolver(bullets: Fv02)
    print("Gun 1")
    gun3.print_magazine()
    print("Gun 2")
    gun4.print_magazine()
    print("Shooting gun 1")
    gun3.shoot()
    gun3.shoot()
    gun3.shoot()
    gun3.shoot()
    gun3.shoot()
    gun3.shoot()
    print("Shooting gun 2")
    gun4.shoot()
    gun4.shoot()
    gun4.shoot()
    gun4.shoot()
    gun4.shoot()
    gun4.shoot()

} catch MyError.invalidInput(let name) {
    print(name)
} catch MyError.invalidBulletType(let name){
    print(name)
} catch {
}
//var magazine3: [Int?] = [nil, nil, nil, nil, nil, nil]
