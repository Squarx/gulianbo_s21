import Foundation
//  /Users/gulianbo/Swift/Swift_Bootcamp._Day02-1/src/Sources/Task2/data-sets/export.txt
//  /Users/gulianbo/Swift/Swift_Bootcamp._Day02-1/src/Sources/Task2/data-sets/resume.txt


print("Enter a path for file1")
let path1 = readLine()!
print("Enter a path for file2")
let path2 = readLine()!
if (cmp_files(path1: path1, path2: path2)) {
    print("Files are identical")
} else {
    print("Files are NOT identical")
}

func readDataBest(_ fileName: String) -> String? {
    guard let data1 = FileManager.default.contents(atPath: fileName)
            else {return nil}
    if let fileData = String(data: data1, encoding: .utf8) {
        return fileData
    } else {
        return nil
    }
}

func readData(_ fileName: String) -> String? {
    let tagFilePath = URL(fileURLWithPath: fileName)
    do {
        let fileData = try Data(contentsOf: tagFilePath)
        if let fileContents = String(data: fileData, encoding: .utf8) {
           return fileContents
        }
    } catch {
        print("Incorrect file")
    }
    return nil
}

func cmp_files1(path1: String, path2: String) -> Bool {
    if (readData(path1) == readFile(path2)) {
        return true
    } else {
        return false
    }
}


func cmp_files(path1: String, path2: String) -> Bool {
    guard let data1 = FileManager.default.contents(atPath: path1), let data2 = FileManager.default.contents(atPath: path2)
            else {
        return false
    }
    return data2 == data1
}

/**
 - Parameter fileName: Файл в текущей директории файла
 - Returns: Str of content or nil
 */
func readFile(_ fileName: String) -> String? {
    var contents: String
    let t = FileManager()
    do {
        contents = try String(contentsOfFile: t.currentDirectoryPath + "/Test/" + fileName)
        print(contents)
        return contents
    } catch {
        print("Ошибка чтения файла: \(error)")
    }
    return nil
}

/**

 - Parameters:
   - fileName: Принимает название файла для текущей директрории где лежит сам файл
   - data:
 */
func writeFile(_ fileName: String, _ data: String) {
    let t = FileManager()
    let filePath = t.currentDirectoryPath
    let url = URL(fileURLWithPath: filePath)
    let newURL = url.appendingPathComponent("Test/" + fileName)
    print("Save path: \(newURL)")
    do {
        let data = data.data(using: .utf8)
        try data?.write(to: newURL)
    } catch {
        print("Error writing to file: \(error)")
    }
}


/*
 let tagFilePath = URL(fileURLWithPath: "Sources/Task2/Resources/resume.txt")
        var arrayTags: [String] = []

        do {
            let fileData = try Data(contentsOf: tagFilePath)
            if let fileContents = String(data: fileData, encoding: .utf8) {
                let words = fileContents.components(separatedBy: .newlines)
                for word in words {
                    arrayTags.append(word)
                }
             } else {
                 return nil
             }
        } catch {
            return nil
        }
        return arrayTags
 */