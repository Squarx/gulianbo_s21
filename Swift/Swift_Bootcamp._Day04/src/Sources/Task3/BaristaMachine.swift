
import Foundation
import Foundation
class BaristaMachine {
    var name: String
    var coffee: [CoffeeShop]
    var time: String = "Coffee is brewing. One minute - time left"
    init(_ name: String, _ coffee: [CoffeeShop]) {
        self.name = name
        self.coffee = coffee
    }
    func printMenue() {
        var num = 1
        for drink in coffee {
            print("\(num). \(drink.name) \(drink.price * 0.9)$")
            num += 1
        }
        print("\n")
    }
    
    func brew(coffee : CoffeeShop) {
        print("\(coffee.name) is is brewing. One minute - time left")
        print("Coffee is ready!")
    }
}
