import Foundation

extension String {
    func convert_num() -> String {
        var ready = ""
        if (validatePhoneNumber(self)) {
            var oper: String
            var index_start: Swift.String.Index
            (oper, index_start) = get_operator(str: self)
            if (oper == "800") {
                ready = "8 (" + oper + ") "
                ready += self[self.index(index_start, offsetBy: 3)..<self.index(index_start, offsetBy: 3 + 3)] + " "
                ready += self[self.index(index_start, offsetBy: 6)..<self.index(index_start, offsetBy: 6 + 2 )] + " "
                ready += self[self.index(index_start, offsetBy: 8)..<self.index(index_start, offsetBy: 8 + 2 )]

            } else {
                ready = "+7 " + oper + " "
                ready += self[self.index(index_start, offsetBy: 3)..<self.index(index_start, offsetBy: 3 + 3)] + "-"
                ready += self[self.index(index_start, offsetBy: 6)..<self.index(index_start, offsetBy: 6 + 2 )] + "-"
                ready += self[self.index(index_start, offsetBy: 8)..<self.index(index_start, offsetBy: 8 + 2 )]
            }
        } else {
            ready = self
        }
        return  ready
    }
    func validatePhoneNumber(_ phoneNumber: String) -> Bool {
        let pattern = "^(\\+7|7|8)[0-9]{10}$"
        let regex = try! NSRegularExpression(pattern: pattern)
        let range = NSRange(location: 0, length: phoneNumber.utf16.count)
        return regex.firstMatch(in: phoneNumber, options: [], range: range) != nil
    }
    func get_operator(str: String) -> (String, Swift.String.Index) {
        var ready_num = ""
        let ind_start_num = str[str.startIndex] == "+" ? 1 : 0
        let ind_start = str.index(str.startIndex, offsetBy: ind_start_num + 1)
        let index = str.index(str.startIndex, offsetBy: 3 + ind_start_num + 1)
        ready_num += str[ind_start..<index]
        return (ready_num, ind_start)
    }
}
var inp = readLine()!
print(inp.convert_num())
//var phone0 = "79966058737"
//var phone1 = "89966058737"
//var phone2 = "+79966058737"
//var phone3 = "78006058737"
//var phone4 = "88006058737"
//var phone5 = "+78006058737"
//var not_phone1 = "+7800605873"
//var not_phone2 = "+7800605873a"
//var ex1 = "88005553535"
//var ex2 = "89152342343"
//print(phone0.convert_num())
//print(phone1.convert_num())
//print(phone2.convert_num())
//print(phone3.convert_num())
//print(phone4.convert_num())
//print(phone5.convert_num())
//print(not_phone1.convert_num())
//print(not_phone2.convert_num())
//print(ex1.convert_num())
//print(ex2.convert_num())



//print(\( (validatePhoneNumber(num) == true) ? "Succ" : "Failure") )

/*
 fun String.masks(): String {
    var mask1 = "^[7|8][0-9]{10}".toRegex()
    var mask2 = "^[+7][0-9]{11}".toRegex()
    var num_arr: String = ""
    var tmp = if (this.contains(mask2) && this.length == 12) this.substring(1,12) else this
    num_arr = if (tmp.contains(mask1) && (tmp.length == 11)) {
        if (tmp.substring(0, 4).contains("[7|8](800)".toRegex()))
            "8" + " (800) " + tmp.substring(4, 7) + tmp.substring(7, 9) + tmp.substring(9, 11)
        else
            "+7 " + tmp.substring(1, 4) + " " + tmp.substring(4, 7) + "-" + tmp.substring(7, 9) + "-" + tmp.substring(9, 11)
    } else {
        this
    }
    return num_arr
}
 */