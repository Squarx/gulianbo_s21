import Foundation
import RealmSwift
import RxSwift
import RxRealm


func ggwp() {
    let myRecipe = RecipeRepository();
            myRecipe.createRecipe(name: "Борщ",
                                  cookingInstruction: "Нарезать говядину кубиками, залить 2 литрами воды и довести до кипения. Снять пену и варить на медленном огне 1,5 часа.",
                                  photoURL: "Borch.jpg")
            .subscribe(onError: { error in
                print("Ошибка при создании рецепта: \(error.localizedDescription)")
            }, onCompleted: {
                print("Рецепт успешно создан")
            })
            .disposed(by: DisposeBag())
            myRecipe.createRecipe(name: "Салат Цезарь",
                                  cookingInstruction: "Подготовьте ингредиенты: нарежьте курицу кубиками, натрите сыр, нарежьте хлеб на кубики и запеките его в духовке до золотистого цвета",
                                  photoURL: "Cesar.jpg")
            .subscribe(onError: { error in
                print("Ошибка при создании рецепта: \(error.localizedDescription)")
            }, onCompleted: {
                print("Рецепт успешно создан")
            })
            .disposed(by: DisposeBag())
            myRecipe.createRecipe(name: "Суши",
                                  cookingInstruction: "\n1.Положите нори на бамбуковый стеллаж (мат) для суши, на него выложите рис и равномерно распределите по всей площади. Поверх риса выложите полоски рыбы, огурца и авокадо.\n2.Сверните нори с начинкой в рулоны, прижимая их пальцами, чтобы они не распались. Осторожно разрежьте рулоны на кусочки и подайте на стол вместе с соевым соусом, васаби и имбирем.",
                                  photoURL: "https://edu.21-school.ru/spaghetti_bolognese.jpg")
            .subscribe(onError: { error in
                print("Ошибка при создании рецепта: \(error.localizedDescription)")
            }, onCompleted: {
                print("Рецепт успешно создан")
            })
            .disposed(by: DisposeBag())
    
    myRecipe.readAllRecipes().subscribe(onNext: { elem in
            print("\nPrint All Ricepe\n\(elem)")
        }, onError: { error in
            print("Ошибка при чтении рецептов: \(error.localizedDescription)")
        }).disposed(by: DisposeBag())
        
        myRecipe.readAllRecipes().subscribe (onNext: { results in
            myRecipe.deleteRecipe(recipe: results[0])
                .subscribe(onError: { error in
                    print("Ошибка при удалении рецепта: \(error.localizedDescription)")
                }, onCompleted: {
                    print("Рецепт успешно удален")
                })
                .disposed(by: DisposeBag())
        }, onError: { error in
            print("Ошибка при чтении рецептов: \(error.localizedDescription)")
        }).disposed(by: DisposeBag())
        
        myRecipe.readAllRecipes().subscribe(onNext: { elem in
            print("\nPrint All Ricepe after delete\n\(elem)")
        }, onError: { error in
            print("Ошибка при чтении рецептов: \(error.localizedDescription)")
        }).disposed(by: DisposeBag())
        
        
        myRecipe.readAllRecipes().subscribe(onNext: { elem in
            myRecipe.updateRecipe(recipe: elem[0], name: "Pizza", cookingInstruction: "Eat when code", photoURL: "https://edu.21-school.ru/pizza.jpg")
                .subscribe(onError: { error in
                    print("Ошибка при обновлении рецепта: \(error.localizedDescription)")
                }, onCompleted: {
                    print("Рецепт успешно обновлен")
                }).disposed(by: DisposeBag())
        }, onError: { error in
            print("Ошибка при чтении рецептов: \(error.localizedDescription)")
        }).disposed(by: DisposeBag())
        
        myRecipe.readAllRecipes().subscribe(onNext: { elem in
            print("\nPrint All Ricepe after update\n\(elem)")
        }, onError: { error in
            print("Ошибка при чтении рецептов: \(error.localizedDescription)")
        }).disposed(by: DisposeBag())
        
        
        myRecipe.searchRecipeByName(name: "Pizza")
            .subscribe(onNext: { elem in
                print("\nPrint find Ricepe\n\(elem)")
            },
                       onError: { error in
                print("Ошибка при поске рецепта: \(error.localizedDescription)")
            })
            .disposed(by: DisposeBag())
        
        
        myRecipe.readAllRecipes().subscribe(onNext: { elem in
            print("\nPrint All Ricepe after all operations\n\(elem)")
        }, onError: { error in
            print("Ошибка при чтении рецептов: \(error.localizedDescription)")
        }).disposed(by: DisposeBag())
        
    }


    ggwp()
