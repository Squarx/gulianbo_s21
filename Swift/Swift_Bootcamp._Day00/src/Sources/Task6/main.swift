import Foundation

func main() {
    print("The program is running. Enter a number or type 'exit' to stop:")
    var numb:Int? = 0
    var count = 1
    while (true) {
        if count % 5 == 0 {
            print("Enter a number or type 'exit' to stop")
        } else if count != 1 {
            print("Enter a number:")
        }
        numb = reader()
        if numb == nil {
            print("Bye!")
            break
        }
        parser(num: numb!)
        count += 1
    }
}

func reader() -> Int? {
    var numb:Int? = 0
    var flag = 1
    while (flag == 1) {
        flag = 0
        let str = readLine()
        if str == "exit" {
            return nil
        }
        numb = Int(str!)
        if numb == nil {
            print("Incorrect format, try again.\nEnter a number:")
            flag = 1;
        }
    }
    return numb
}

func parser(num : Int) {
    var list:Array<String> = [String]()
    var numb = num
    var part = 0
    var i = 1
    var flag = 0
    while (numb > 0) {
        part = (numb % 10)
        numb = (numb / 10)
        let result = numbCheck(num: part, i: i, list: list)
        if flag == 1 || result.flag == 1 { list.removeFirst(); flag = 0 }
        if result.str == "zero" { flag = 1 }
        list.insert(result.str, at: 0)
        i += 1
    }
    printer(list:list)
}
func printer(list:Array<String>) {
    var j = 0
    let i = list.count
    var result = ""
    while (j < i) {
        result += String(list[j]) + " "
        j += 1
    }
    print(result)
}

func numbCheck(num: Int, i: Int, list: Array<String>) -> (str: String, flag: Int) {
    var str = ""
    var flag = 0
    if num == 1 {
        if i == 2 || i == 5 { flag = 1 }
        if i == 2 {str = oneParse(num: num, list: list)}
        else {str = "one"}
    } else if num == 2 {
        if i == 2 || i == 5 {str = "twenty"}
        else {str =  "two"}
    } else if num == 3 {
        if i == 2 || i == 5 {str = "thirty"}
        else {str = "three"}
    } else if num == 4 {
        if i == 2 || i == 5 {str = "forty"}
        else {str = "four"}
    } else if num == 5 {
        if i == 2 || i == 5 {str = "fifty"}
        else {str = "five"}
    } else if num == 6 {
        if i == 2 || i == 5 {str = "sixty"}
        else {str = "six"}
    } else if num == 7 {
        if i == 2 || i == 5 {str = "seventy"}
        else {str = "seven"}
    } else if num == 8 {
        if i == 2 || i == 5 {str = "eighty"}
        else {str = "eight"}
    } else if num == 9 {
        if i == 2 || i == 5 {str = "ninety"}
        else {str = "nine"}
    } else {
        str = "zero"
    }
    if str != "zero" {
    if i == 3 || i == 6 { str += " hundred"}
    if i == 4 { str += " thousand"}
    if i == 7 { str += " million"}
    }
    return (str, flag)
}

func oneParse(num: Int, list: Array<String>) -> String {
    var str = ""
    if list[0] == "zero" {
        str = "ten"
    } else if list[0] == "one" {
        str = "eleven"
    } else if list[0] == "two" {
        str = "twelve"
    } else if list[0] == "three" {
        str = "thirteen"
    } else if list[0] == "four" {
        str = "fourteen"
    } else if list[0] == "five" {
        str = "fiveteen"
    } else if list[0] == "six" {
        str = "sixteen"
    } else if list[0] == "seven" {
        str = "seventeen"
    } else if list[0] == "eight" {
        str = "eightteen"
    } else if list[0] == "nine" {
        str = "nineteen"
    }
    return str
}

main()