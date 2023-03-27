//
//  File.swift
//  
//
//  Created by Gulian Boris on 3/24/23.
//

import Foundation
import Swinject

protocol Animal {
    var name: String? { get }
}

class Cat: Animal {
let name: String?

   init(name: String?) {
self.name = name  }
    
}

class Dog: Animal {
let name: String?

   init(name: String?) {
self.name = name  }
    
}

protocol Person {
    func play()
}

class PetOwner: Person {
    let pet: Animal

    init(pet: Animal) {
        self.pet = pet
    }

    func play() {
        let name = pet.name ?? "someone"
        print("I'm playing with \(name).")
    }
}

let container = Container()
container.register(Animal.self) { _ in Cat(name: "Mimi") }; container.register(Person.self) { r in
    PetOwner(pet: r.resolve(Animal.self)!)
}
let person = container.resolve(Person.self)!
person.play() // prints "I'm playing with Mimi."

container.register(Animal.self) { _ in Dog(name: "Fido") };

// Создание экземпляра PetOwner с зависимостью Dog
let person2 = container.resolve(Person.self)!
person2.play() // prints "I'm playing with Fido."
