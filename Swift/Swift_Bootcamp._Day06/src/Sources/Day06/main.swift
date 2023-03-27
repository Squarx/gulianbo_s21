import Foundation
import RealmSwift
import Realm


let myRecipe = RecipeDataBase();
myRecipe.clearTable()
myRecipe.createRecipe(name: "Борщ",
                      cookingInstruction: "Нарезать говядину кубиками, залить 2 литрами воды и довести до кипения. Снять пену и варить на медленном огне 1,5 часа.",
                      photoURL: "Borch.jpg")
myRecipe.createRecipe(name: "Борщ",
                      cookingInstruction: "Нарезать говядину кубиками, залить 2 литрами воды и довести до кипения. Снять пену и варить на медленном огне 1,5 часа.",
                      photoURL: "Borch.jpg")
myRecipe.createRecipe(name: "Салат Цезарь",
                      cookingInstruction: "Подготовьте ингредиенты: нарежьте курицу кубиками, натрите сыр, нарежьте хлеб на кубики и запеките его в духовке до золотистого цвета",
                      photoURL: "Cesar.jpg")
myRecipe.createRecipe(name: "Суши",
                      cookingInstruction: "\n1.Положите нори на бамбуковый стеллаж (мат) для суши, на него выложите рис и равномерно распределите по всей площади. Поверх риса выложите полоски рыбы, огурца и авокадо.\n2.Сверните нори с начинкой в рулоны, прижимая их пальцами, чтобы они не распались. Осторожно разрежьте рулоны на кусочки и подайте на стол вместе с соевым соусом, васаби и имбирем.",
                      photoURL: "https://edu.21-school.ru/spaghetti_bolognese.jpg")

print("\nPrint All Ricepies\n\(myRecipe.readAllData())")


myRecipe.deleteByName(name: "Борщ")
print("\nPrint All Ricepies Without Борщ\n\(myRecipe.readAllData())")

myRecipe.updateRecipe(recipe: myRecipe.readAllData()[0], name: "Pizza", cookingInstruction: "Pizza with pineapples the best", photoURL: "Pineapple.jpg")
print("\n\nPrint All Ricepe after update\n\(myRecipe.readAllData())")
//
print("\n\nPrint find Ricepe\n\(myRecipe.searchRecipeByName(name: "Pizza"))")
//
print("\n\nPrint All Ricepe after all operations\n\(myRecipe.readAllData())")

print("\nPrint All Ricepies\n\(myRecipe.readAllData())")



