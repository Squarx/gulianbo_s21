//
//  File.swift
//  
//
//  Created by Gulian Boris on 3/22/23.
//

import Foundation
import RealmSwift
import Realm

class Recipe: Object {
    //    @Persisted(primaryKey: true) var _id: ObjectId
    @objc dynamic var name: String = ""
    @objc dynamic var cookingInstruction: String = ""
    @objc dynamic var photoURL: String = ""
    convenience init(_ name: String, _ cookingInstruction: String, _ photoURL: String) {
        self.init()
        self.name = name
        self.cookingInstruction = cookingInstruction
        self.photoURL = photoURL
    }
}

class RecipeDataBase {
    private let realm: Realm
    
    init() {
        realm = try! Realm()
    }
    
    
    func createRecipe(name: String, cookingInstruction: String, photoURL: String) {
        let recipe = Recipe( name,cookingInstruction, photoURL)
        try! realm.write {
            realm.add(recipe)
        }
    }
    
    func readAllData() -> Results<Recipe> {
        return realm.objects(Recipe.self)
    }
    
    func updateRecipe(recipe: Recipe, name: String, cookingInstruction: String, photoURL: String) {
        try! realm.write {
            recipe.name = name
            recipe.cookingInstruction = cookingInstruction
            recipe.photoURL = photoURL
        }
    }
    
    func deleteRecipe(recipe: Recipe) {
        try! realm.write {
            realm.delete(recipe)
        }
    }
    
    func searchRecipeByName(name: String) -> Results<Recipe> {
        return realm.objects(Recipe.self).filter("name CONTAINS[c] %@", name)
    }
    
    func clearTable() {
        try! realm.write{
            realm.deleteAll()
        }
    }
    func deleteByName(name: String) {
        try! realm.write{
            realm.delete(realm.objects(Recipe.self).filter("name CONTAINS[c] %@", name))
        }
    }
}
