//
// Created by Gulian Boris on 3/16/23.
//

import Foundation

class Candidate {
    var person: Person
    var education: Education
    var experience: [Experience]
    var additional: AdditionalInfo

    init(_ person: Person, _ education: Education, _ experience: [Experience], _ additional: AdditionalInfo) {
        self.person = person
        self.education = education
        self.experience = experience
        self.additional = additional
    }

    func print_data() {
        person.print_data()
        education.print_data()
        for i in experience {
            i.print_data()
        }
        print(additional.Info)
    }

    func data_tostr() -> String {
        var result = "# Candidate info\n"
        result += person.FIO + "\n"
        result += person.Prof + "\n"
        result += person.Sex + "\n"
        result += person.Birth + "\n"
        result += person.Phone + "\n"
        result += person.Email + "\n"
        result += person.Ready + "\n\n"
        result += "# Education\n"
        result += education.EdType + "\n"
        result += education.EdYear + "\n"
        result += education.Description + "\n"
        result += "\n"
        result += "# Job experience\n"
        for i in experience {
            result += "##\n"
            result += i.Dates + "\n"
            result += i.Company + "\n"
            result += i.Description + "\n"
        }
        result += "\n"
        result += "# Free block\n"
        result += additional.Info + "\n"
        return result
    }
}


class Person {
    var FIO: String = ""
    var Prof: String = ""
    var Sex: String = ""
    var Birth: String = ""
    var Phone: String = ""
    var Email: String = ""
    var Ready: String = ""

    init(FIO: String, Prof: String, Sex: String, Birth: String, Phone: String, Email: String, Ready: String) {
        self.FIO = FIO
        self.Prof = Prof
        self.Sex = Sex
        self.Birth = Birth
        self.Phone = Phone
        self.Email = Email
        self.Ready = Ready
    }

    func print_data() {
        print("FIO = \(FIO)")
        print("Prof = \(Prof)")
        print("Sex = \(Sex)")
        print("Birth = \(Birth)")
        print("Phone = \(Phone)")
        print("Email = \(Email)")
        print("Ready = \(Ready)")

    }
}

class Education {
    var EdType: String = ""
    var EdYear: String = ""
    var Description: String = ""

    init(EdType: String, EdYear: String, Description: String) {
        self.EdType = EdType
        self.EdYear = EdYear
        self.Description = Description
    }

    func print_data() {
        print("EdType = \(EdType)")
        print("EdYear = \(EdYear)")
        print("Description = \(Description)")
        print("------------------------")
    }
}

class Experience {
    var Dates: String = ""
    var Company: String = ""
    var Description: String = ""

    init(Dates: String, Company: String, Description: String) {
        self.Dates = Dates
        self.Company = Company
        self.Description = Description
    }

    func print_data() {
        print("Dates = \(Dates)")
        print("Company = \(Company)")
        print("Description = \(Description)")
        print("------------------------")
    }
}

class AdditionalInfo {
    var Info: String = ""

    init(Info: String) {
        self.Info = Info
    }
}