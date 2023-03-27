import Foundation

var T = Candidate(Name: "Ivan", Activity: "Banking", Profession: "Project Manager", Level: "Junior", Salary: "110000", Skills: ["python", "matlab"])
T.print_task()
var Big_slt = compListCreate()
var tmp = My_list(elements: Big_slt)
var ready_lst = tmp.filter_list(T)
print("Write a num of this list")
var ind = Int(readLine()!)!
print("Proccessing Interview...")
if tmp.interview(varible: ind, candidate: T, ready_lst) {
    print("Success, candidate was applied.")
} else {
    print("Fail, candidate was not applied.")
}

class Company {
    var Name: String = ""
    var Field: String = ""
    var Description: String = ""
    var Vacancies: Vacancies
    var Contacts: String = ""

    init(Name: String, Field: String, Description: String, Vacancies: Vacancies, Contacts: String) {
        self.Name = Name
        self.Field = Field
        self.Description = Description
        self.Vacancies = Vacancies
        self.Contacts = Contacts
    }

}

class Vacancies {
    var Profession: String = ""
    var Level: String = ""
    var Salary: String = ""

    init(profession: String, level: String, salary: String) {
        self.Profession = profession
        self.Level = level
        self.Salary = salary
    }
}

struct My_list {
    var List = [Company]()

//    var Ready_lst = [Company]()
    init(elements: [Company]) {
        self.List = elements
    }

    subscript(position: Int) -> Company {
        return List[position]
    }

    func filter_list(_ candidate: Candidate) -> [Company] {
        var cnt = 1
        var ready_comp = [Company]()
        for company in self.List {
            if (company.Vacancies.Level == candidate.Level && candidate.Activity == company.Field && candidate.Profession == company.Vacancies.Profession) {
                print("\(cnt).")
                print_company(company)
                cnt += 1
                print("------------------------------")
                ready_comp.append(company)
            }
        }
        return ready_comp
    }

    func print_company(_ company: Company) {
        print("\(company.Vacancies.Level) \(company.Vacancies.Profession)     ---     from \(company.Vacancies.Salary)")
        print(company.Name)
        print(company.Field)
//        print(company.Description)
//        print(company.Contacts)
    }

    func interview(varible: Int, candidate: Candidate, _ companies: [Company]) -> Bool {
        if (companies.count >= varible - 1) {
            let company = companies[varible - 1]
            let skills = get_skills(company: company)
            var res = 0
            for skill in skills {
                if candidate.Skills.contains(skill) {
                    res += 1
                }
            }
            return Double(res / skills.count) > 0.5
        } else {
            return false
        }
    }
}

func get_skills(company: Company) -> [String] {
    var res: [String]
    switch company.Field {
    case "Banking":
        let gg = Bankink_skills(company: company)
        switch gg {
        case .google(let items), .sber(let items), .tinkoff(let items), .yandex(let items), .ddr(let items), .gucci(let items), .uty(let items), .rzd(let items), .skb(let items), .sinara(let items), .gg(let items):
            res = items
        }
    case "IT":
        res = ["python", "matlab"]
    case "Public services":
        res = ["figma", "Photoshope"]
    default:
        res = ["Amogus"]
    }

    return res
}

enum Bankink_skills {
    case google(items: [String])
    case sber(items: [String])
    case tinkoff(items: [String])
    case yandex(items: [String])
    case ddr(items: [String])
    case gucci(items: [String])
    case uty(items: [String])
    case rzd(items: [String])
    case skb(items: [String])
    case sinara(items: [String])
    case gg(items: [String])

    init(company: Company) {
        switch company.Name {
        case "Google":
            self = .google(items: ["CSS", "SQL", "C++", "matlab", "python"])
        case "SBER":
            self = .sber(items: ["CSS", "SQL", "C++"])
        case "Tinkoff":
            self = .tinkoff(items: ["CSS", "SQL", "C++"])
        case "Yandex":
            self = .yandex(items: ["CSS", "SQL", "C++"])
        case "DDR":
            self = .ddr(items: ["CSS", "SQL", "C++"])
        case "Gucchi":
            self = .gucci(items: ["CSS", "SQL", "C++"])
        case "UTY":
            self = .uty(items: ["CSS", "SQL", "C++"])
        case "RZD":
            self = .rzd(items: ["CSS", "SQL", "C++"])
        case "SKB":
            self = .skb(items: ["CSS", "SQL", "C++"])
        case "Sinara":
            self = .sinara(items: ["python", "matlab"])
        default:
            self = .gg(items: ["CSS", "SQL", "C++"])
        }
    }
}

func compListCreate() -> [Company] {
    let V0 = Vacancies(profession: "Project Manager", level: "Junior", salary: "50000")
    let C0 = Company(Name: "Google", Field: "Banking", Description: "Its Googggle", Vacancies: V0, Contacts: "8 (800) 555-44-33")
    let V1 = Vacancies(profession: "Developer", level: "Middle", salary: "65000")
    let C1 = Company(Name: "SBER", Field: "Banking", Description: "best", Vacancies: V1, Contacts: "+7 999 345-67-89")
    let V2 = Vacancies(profession: "Developer", level: "Senior", salary: "75000")
    let C2 = Company(Name: "Tinkoff", Field: "Banking", Description: "good", Vacancies: V2, Contacts: "+7 999 999-99-99")
    let V3 = Vacancies(profession: "QA", level: "Junior", salary: "69000")
    let C3 = Company(Name: "Yandex", Field: "IT", Description: "good", Vacancies: V3, Contacts: "8 (800) 555-35-35")
    let V4 = Vacancies(profession: "QA", level: "Junior", salary: "35000")
    let C4 = Company(Name: "DDR", Field: "Public services", Description: "good", Vacancies: V4, Contacts: "8 (800) 777-88-99")
    let V5 = Vacancies(profession: "Designer", level: "Senior", salary: "81000")
    let C5 = Company(Name: "Gucchi", Field: "Public services", Description: "good", Vacancies: V5, Contacts: "8 (800) 555-22-22")
    let V6 = Vacancies(profession: "Designer", level: "Senior", salary: "53223")
    let C6 = Company(Name: "H&M", Field: "Public services", Description: "good", Vacancies: V6, Contacts: "8 (800) 598-45-55")
    let V7 = Vacancies(profession: "Designer", level: "Senior", salary: "52131")
    let C7 = Company(Name: "UTY", Field: "IT", Description: "good", Vacancies: V7, Contacts: "8 (800) 666-33-22")
    let V8 = Vacancies(profession: "Designer", level: "Junior", salary: "25723")
    let C8 = Company(Name: "RZD", Field: "Public services", Description: "good", Vacancies: V8, Contacts: "8 (800) 555-33-22")
    let V9 = Vacancies(profession: "Project Manager", level: "Junior", salary: "130231")
    let C9 = Company(Name: "SKB", Field: "Banking", Description: "good", Vacancies: V9, Contacts: "8 (800) 999-33-22")
    let V10 = Vacancies(profession: "Project Manager", level: "Junior", salary: "40000")
    let C10 = Company(Name: "Sinara", Field: "Banking", Description: "good", Vacancies: V10, Contacts: "8 (800) 333-22-22")
    let CompList = [Company](arrayLiteral: C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10)
    return CompList
}
