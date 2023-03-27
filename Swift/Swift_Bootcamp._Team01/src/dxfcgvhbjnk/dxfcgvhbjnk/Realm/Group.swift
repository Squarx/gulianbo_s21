//
//  Group.swift
//  dxfcgvhbjnk
//
//  Created by Gulian Boris on 3/25/23.
//
import Foundation
import RealmSwift

final class Group: Object, ObjectKeyIdentifiable {
    
    @Persisted(primaryKey: true) var _id: ObjectId
    
    @Persisted var items = RealmSwift.List<Item>()

}


func load<Recipe: Decodable>(_ filename: String) -> Recipe {
    let data: Data

    guard let file = Bundle.main.url(forResource: filename, withExtension: nil)
    else {
        fatalError("Couldn't find \(filename)")
    }

    do {
        data = try Data(contentsOf: file)
    } catch {
        fatalError("Couldn't load \(filename) \n\(error)")
    }

    do {
        let decoder = JSONDecoder()
        return try decoder.decode(Recipe.self, from: data)
    } catch {
        fatalError("Couldn't parse \(filename) \n\(error)")
    }
}
