//
// Created by Gulian Boris on 3/15/23.
//

import Foundation

class Candidate {
    var Name: String = ""
    var Activity: String = ""
    var Profession: String = ""
    var Level: String = ""
    var Salary: String = ""
    var Skills = [String]()

    init(Name: String, Activity: String, Profession: String, Level: String, Salary: String, Skills: [String]) {
        self.Name = Name
        self.Activity = Activity
        self.Profession = Profession
        self.Level = Level
        self.Salary = Salary
        self.Skills = Skills
    }

    func print_info() {
        print("Candidate:")
        print("- Name: \(Name)")
        print("- Activity: \(Activity)")
        print("- Profession: \(Profession)")
        print("- Level: \(Level)")
        print("- Salary: \(Salary)")
        print("- Skills: \(Skills)")
    }

    func print_task() {
        print("\(Activity). \(Profession). \(Level). > \(Salary)")
    }

}

