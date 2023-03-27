import Foundation
func valid_Int() -> Int {
    if let num = Int(readLine()!), [1, 2].contains(num) {
        return num
    } else {
        print("INcorrect input Try again")
        return valid_Int()
    }
}
print("Choose barista:\n1. Man\n2. Machine")
var num = valid_Int()
var Сappuccino = CoffeeShop(name: "Сappuccino", price: 2.0)
var Americano = CoffeeShop(name: "Americano", price: 1.5)
var Latte = CoffeeShop(name: "Latte", price: 2.3)
var machine = BaristaMachine("Aboba", [Сappuccino, Americano, Latte])
var ManOne  = Barista(name: "SerGay", surname: "Mort", experience: "1 Year")
if (num == 2) {
    machine.printMenue()
    print("Enter your choice (1-3):")
    var num  = 0
    while num < 1 && num < 3 {
        num  = valid_Int()
    }
    switch num {
    case 1:
        machine.brew(coffee: Сappuccino)
    case 2:
        machine.brew(coffee: Americano)
    case 3:
        machine.brew(coffee: Latte)
    default:
        print("")
    }
    } else {
        print("Enter your choice (1-3):")
        printMenueBarista(coffee: [Сappuccino, Americano, Latte])
        var num  = 0
        while num < 1 && num < 3 {
            num  = valid_Int()
        }
        switch num {
        case 1:
            ManOne.brew(Сappuccino)
        case 2:
            ManOne.brew(Americano)
        case 3:
            ManOne.brew(Latte)
        default:
            print("")
    }
}


func printMenueBarista(coffee: [CoffeeShop]) {
    var num = 1
    for drink in coffee {
        print("\(num). \(drink.name) \(drink.price)$")
        num += 1
    }
}
