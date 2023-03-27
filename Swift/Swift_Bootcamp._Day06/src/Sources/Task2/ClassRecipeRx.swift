import Foundation
import RealmSwift
import RxSwift
import RxRealm

class Recipe: Object {
    @objc dynamic var name = ""
    @objc dynamic var cookingInstruction = ""
    @objc dynamic var photoURL: String = ""
}

class RecipeRepository {
    private let realm: Realm
    
    init() {
        realm = try! Realm()
    }
    
    func createRecipe(name: String, cookingInstruction: String, photoURL: String) -> Observable<Void> {
        return Observable.deferred {
            let recipe = Recipe()
            recipe.name = name
            recipe.cookingInstruction = cookingInstruction
            recipe.photoURL = photoURL
            
            try! self.realm.write {
                self.realm.add(recipe)
            }
            
            return Observable.just(())
        }
    }
    
    func readAllRecipes() -> Observable<Results<Recipe>> {
        return Observable.deferred {
            return Observable.collection(from: self.realm.objects(Recipe.self))
        }
    }
    
    func updateRecipe(recipe: Recipe, name: String, cookingInstruction: String, photoURL: String) -> Observable<Void> {
        return Observable.deferred {
            try! self.realm.write {
                recipe.name = name
                recipe.cookingInstruction = cookingInstruction
                recipe.photoURL = photoURL
            }
            
            return Observable.just(())
        }
    }
    
    func deleteRecipe(recipe: Recipe) -> Observable<Void> {
        return Observable.deferred {
            try! self.realm.write {
                self.realm.delete(recipe)
            }
            
            return Observable.just(())
        }
    }
    
    func searchRecipeByName(name: String) -> Observable<Results<Recipe>> {
        let results = realm.objects(Recipe.self).filter("name CONTAINS[c] %@", name)
        return Observable.collection(from: results)
    }
}
