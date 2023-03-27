import Foundation

//let filePath = "/Users/marlinto/Desktop/swift/Swift_Bootcamp._Day02-1/src/Sources/ex02/input.txt"

//print(t.contents(atPath: <#T##String#>))

//var filename = "main.swift"
let gg  = "spdifjekprovf \noseudcinwdcsadivouwisqmpkwcdjsvncos\tmmasndisvjackmdnmlvjnmls\tfslvdjancskldvsjc\nlkdsnfc\taklsnceFf\twqed"
//print(readFile(filename) ?? "123")
writeFile("test.txt", gg)


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