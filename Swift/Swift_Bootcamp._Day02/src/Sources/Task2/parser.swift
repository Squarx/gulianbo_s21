//
// Created by Gulian Boris on 3/16/23.
//

import Foundation

func fill_info(data: StreamReader)  -> AdditionalInfo {
    var txt = ""
    while let tmp = data.nextLine(), tmp.count != 0 {
        txt += tmp
    }
    return AdditionalInfo(Info: txt)
}

func fill_exp(data: StreamReader) -> [Experience] {
    var lst_of_exp = [Experience]()
    while var tmp = data.nextLine(), tmp.count != 0 {
        if tmp.contains("##") {
            tmp = data.nextLine()!
        }
        _ = tmp
        let Company = data.nextLine()!
        let Description = data.nextLine()!
        lst_of_exp.append(Experience(Dates: tmp, Company: Company, Description: Description))
    }
    return lst_of_exp
}


func fill_education(data: StreamReader) -> Education {
    let EdType = data.nextLine()!
    let EdYear = data.nextLine()!
    let Description = data.nextLine()!
    return Education(EdType: EdType, EdYear: EdYear, Description: Description)
}

func fill_person(data: StreamReader) -> Person {
    let FIO = data.nextLine()!
    let Prof = data.nextLine()!
    let Sex = data.nextLine()!
    let Birth = data.nextLine()!
    let Phone = data.nextLine()!
    let Email = data.nextLine()!
    let Ready = data.nextLine()!
    return Person(FIO: FIO, Prof: Prof, Sex: Sex, Birth: Birth, Phone: Phone, Email: Email, Ready: Ready)
}


func get_from_sets(filename: String) -> StreamReader? {
    let t = FileManager()
    if let aStreamReader = StreamReader(path: t.currentDirectoryPath + "/Task2/data-sets/" + filename) {
        print("Reading |\(t.currentDirectoryPath + "/Task2/data-sets/" + filename)|")
        return aStreamReader
    } else {
        return nil
    }
}


