//
//  Rclass.swift
//  dxfcgvhbjnk
//
//  Created by Gulian Boris on 3/25/23.
//

import Foundation
import Foundation
import Realm
import RealmSwift

final  class Item: Object, ObjectKeyIdentifiable {
    @Persisted(primaryKey: true) var _id:ObjectId
    @Persisted var name =  "\(randomAdjectives.randomElement()!) \(randomNouns.randomElement()!)"
    @Persisted var isFavorite = false
    // ссылка на что то 
    @Persisted(originProperty: "items") var group: LinkingObjects<Group>
}

final class Recipe: Object, ObjectKeyIdentifiable, Decodable {
    @Persisted(primaryKey: true) var _id:ObjectId
    @Persisted var idRecipe: Int
    @Persisted var title: String
    @Persisted var imageName: String
    @Persisted var descriptionRecipe: String
    @Persisted var ingredients = List<String>()
    @Persisted var steps =  List<Step>()
}

final class Step: Object, ObjectKeyIdentifiable, Decodable {
    @Persisted var idStep: Int
    @Persisted var descriptionStep: String
    @Persisted var imageName: String?
}


/// Random adjectives for more interesting demo item names
let randomAdjectives = [
    "fluffy", "classy", "bumpy", "bizarre", "wiggly", "quick", "sudden",
    "acoustic", "smiling", "dispensable", "foreign", "shaky", "purple", "keen",
    "aberrant", "disastrous", "vague", "squealing", "ad hoc", "sweet"
]
/// Random noun for more interesting demo item names
let randomNouns = [
    "floor", "monitor", "hair tie", "puddle", "hair brush", "bread",
    "cinder block", "glass", "ring", "twister", "coasters", "fridge",
    "toe ring", "bracelet", "cabinet", "nail file", "plate", "lace",
    "cork", "mouse pad"
]
