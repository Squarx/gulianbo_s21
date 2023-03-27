import Foundation




main()
cont_words()



func cont_words() {
    var out = "#Words\n"
    if let data = get_from_sets(filename: "export.txt") {
        let string = data.data_str()

        let words = string.components(separatedBy: CharacterSet.punctuationCharacters.union(CharacterSet.whitespacesAndNewlines)).filter({ !$0.isEmpty })

        var wordCounts: [String: Int] = [:]

        for word in words {
            if let count = wordCounts[word] {
                wordCounts[word] = count + 1
            } else {
                wordCounts[word] = 1
            }
        }

        let sortedCounts = wordCounts.sorted {
            $0.value > $1.value
        }
        let sortedCountsDictionary = Dictionary(uniqueKeysWithValues: sortedCounts)

        for i in sortedCounts {
            out += i.key + " - " + String(i.value) + "\n"
//            print(i.key, i.value)
        }
        var arr_tags = [String]()

        if let data = get_from_sets(filename: "tags.txt") {
            let string = data.data_str()
            arr_tags = string.split(separator: "\n").map {
                String($0)
            }

            out += "\n#Matched tags\n"
            for item in arr_tags {
                if sortedCountsDictionary.keys.contains(item) {
                    out += item + "\n"
                }
            }
        }


        let filename = "analysis_task2.txt"
        let t = FileManager()
        let filePath = t.currentDirectoryPath
        let url = URL(fileURLWithPath: filePath)
        let newURL = url.appendingPathComponent("Task2/data-sets/" + filename)
        let text = out
        print("Save path: \(newURL)")
        do {
            let data = text.data(using: .utf8)
            try data?.write(to: newURL)
        } catch {
            print("Error writing to file: \(error)")
        }
    }
}


    func main() {
        var person = Person(FIO: "", Prof: "", Sex: "", Birth: "", Phone: "", Email: "", Ready: "")
        var education = Education(EdType: "EdType", EdYear: "EdYear", Description: "Description")
        _ = Experience(Dates: "Dates", Company: "Company", Description: "Description")
        var lst_of_exp = [Experience]()
        var info = AdditionalInfo(Info: "")

        // parse form filename == resume.txt
        if let data = get_from_sets(filename: "resume.txt") {
            while let line = data.nextLine() {
                if line.contains("# Candidate info") {
                    person = fill_person(data: data)
                }
                if line.contains("# Education") {
                    education = fill_education(data: data)
                }
                if line.contains("# Job experience") {
                    lst_of_exp = fill_exp(data: data)
                }
                if line.contains("# Free block") {
                    info = fill_info(data: data)
                }
            }
            do {
                data.close()
            }
        }
        let candidate = Candidate(person, education, lst_of_exp, info)
//    candidate.print_data()

// writer in example.txt

        let text: String = candidate.data_tostr()
        let filename = "export.txt"
        let t = FileManager()
        let filePath = t.currentDirectoryPath
        let url = URL(fileURLWithPath: filePath)
        let newURL = url.appendingPathComponent("Task2/data-sets/" + filename)

        print("Save path: \(newURL)")
        do {
            let data = text.data(using: .utf8)
            try data?.write(to: newURL)
        } catch {
            print("Error writing to file: \(error)")
        }
    }



