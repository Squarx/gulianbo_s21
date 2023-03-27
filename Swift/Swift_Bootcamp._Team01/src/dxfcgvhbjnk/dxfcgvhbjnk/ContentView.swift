//
//  ContentView.swift
//  dxfcgvhbjnk
//
//  Created by Gulian Boris on 3/25/23.
//

import SwiftUI
import Foundation
import Realm
import RealmSwift

struct ContentView: View {
    var dog1 = Dog(name: "asd", age: 123)
    var dog2 = Dog(name: "123123asd", age: 11234)
    let realm = try! Realm()
    
    var body: some View {
        NavigationView {
            VStack {
                Button("Add dog 1") {
                    let dog1 = Dog(name: "asd", age: 123)
                    adder(dog: dog1)
                }
                Button("Add dog 2") {
                    let dog2 = Dog(name: "123123asd", age: 11234)
                    adder(dog: dog2)
                }
                Button("Clear data") {
                    clearTable()
                }
                NavigationLink(destination: SecondView(dogs: realm.objects(Dog.self))) {
                    Text("navigation")
                }
                .frame(width: 200, height: 200, alignment: .center)
                .background(.cyan)
                .overlay(
                    Image(systemName: "chevron.right")
                        .foregroundColor(Color(hue: 22, saturation: 0.0, brightness: 0.562))
                        .font(.system(size: 16, weight: .bold))
                        .padding(.trailing, 10),
                    alignment: .trailing)
                
                
            }
            //        Text(dogNames)
            //            .padding()
            //
            //        Text("Hello, world!")
            //            .padding()
        }
    }
    func adder(dog: Dog) {
        try! realm.write {
            realm.add(dog)
        }
    }
    func clearTable() {
        try! realm.write{
            realm.deleteAll()
        }
    }

    
}
struct SecondView: View {
    var dogs: Results<Dog>
    var body: some View {
        let dogNames = dogs.map { $0.name }.joined(separator: "\n")
        return Text(dogNames)
    }
}



struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}


class Dog: Object, Identifiable {
    @Persisted var name: String
    @Persisted var age: Int
    
    convenience init(name: String, age: Int) {
        self.init()
        self.name = name
        self.age = age
    }
}
