//
//  ContentView.swift
//  Recepies
//
//  Created by Gulian Boris on 3/18/23.
//

import SwiftUI

import Foundation

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

struct ContentView: View {
    
    var dishes : [Recipe] = load("data.json")
    var body: some View {
        NavigationView {
            ScrollView {
                ZStack {
                    VStack {
                        Text("Recepies")
                            .font(.system(size: 34))
                            .fontWeight(.bold)
                            .foregroundColor(Color.white)
                            .padding(.top, 40)
                        //                var iter = 1
                        ForEach(Array(dishes.enumerated()), id: \.1.id) { i, recipe in
                            NavigationLink(destination:  SecondView(recept: recipe)) {
                                HStack {
                                    Text("")
                                        .frame(width: 10)
                                    Image("\(recipe.imageName)")
                                        .resizable()
                                        .aspectRatio(contentMode: .fit)
                                        .cornerRadius(10)
                                    //                                .scaleEffect(0.8)
                                        .frame(height: 100)
                                    VStack {
                                        Text("\(i + 1). \(recipe.title)")
                                            .foregroundColor(.white)
                                            .frame(maxWidth: .infinity, alignment: .leading)
                                        //                                    .padding(10)
                                            .padding(.leading, 20)
                                        Text("\(recipe.description)")
                                            .foregroundColor(.white)
                                            .multilineTextAlignment(.leading)
                                            .frame(maxWidth: .infinity, alignment: .leading)
                                        //                                    .padding(10)
                                            .padding(.leading, 20)
                                        
                                    }
                                    .padding(.trailing, -20.0)
                                    .frame(height: 150)
                                    Text("")
                                        .frame(width: 50)
                                }
                                .frame(height: 150)
                            }
                            .overlay(
                                Image(systemName: "chevron.right")
                                    .foregroundColor(Color(hue: 22, saturation: 0.0, brightness: 0.562))
                                    .font(.system(size: 16, weight: .bold))
                                    .padding(.trailing, 10),
                                alignment: .trailing
                            )
                            .background(Color(hue: 22, saturation: 0.127, brightness: 0.465, opacity: 0.189))
                            .cornerRadius(20)
                        }
                        Spacer()
                    }
                }
            }
            .padding(5)
            .frame(width: UIScreen.main.bounds.width, alignment: .leading)
        }
    }
}

struct MenuView: View {
    var Names: [Recipe]
    var body: some View {
        ScrollView {
            ZStack {
                VStack {
                    Text("Recepies")
                        .font(.system(size: 34))
                        .fontWeight(.bold)
                        .foregroundColor(Color.white)
                        .padding(.top, 40)
                    //                var iter = 1
                    ForEach(Array(Names.enumerated()), id: \.1.id) { i, recipe in
                        NavigationLink(destination:  SecondView(recept: recipe)) {
                            HStack {
                                Text("")
                                    .frame(width: 10)
                                Image("\(recipe.imageName)")
                                    .resizable()
                                    .aspectRatio(contentMode: .fit)
                                    .cornerRadius(10)
                                //                                .scaleEffect(0.8)
                                    .frame(height: 100)
                                VStack {
                                    Text("\(i + 1). \(recipe.title)")
                                        .foregroundColor(.white)
                                        .frame(maxWidth: .infinity, alignment: .leading)
                                    //                                    .padding(10)
                                        .padding(.leading, 20)
                                    Text("\(recipe.description)")
                                        .foregroundColor(.white)
                                        .multilineTextAlignment(.leading)
                                        .frame(maxWidth: .infinity, alignment: .leading)
                                    //                                    .padding(10)
                                        .padding(.leading, 20)
                                    
                                }
                                .padding(.trailing, -20.0)
                                .frame(height: 150)
                                Text("")
                                    .frame(width: 50)
                            }
                            .frame(height: 150)
                        }
                        .overlay(
                            Image(systemName: "chevron.right")
                                .foregroundColor(Color(hue: 22, saturation: 0.0, brightness: 0.562))
                                .font(.system(size: 16, weight: .bold))
                                .padding(.trailing, 10),
                            alignment: .trailing
                        )
                        .background(Color(hue: 22, saturation: 0.127, brightness: 0.465, opacity: 0.189))
                        .cornerRadius(20)
                    }
                    Spacer()
                }
            }
        }
        .padding(5)
        .frame(width: UIScreen.main.bounds.width, alignment: .leading)
    }
    
}
struct SecondView: View {
    var recept: Recipe
    var body: some View {
        ScrollView {
            VStack {
                Text("Recipes")
                    .font(.system(size: 34))
                    .fontWeight(.bold)
                    .foregroundColor(Color.white)
                    .frame(width:200, height: 100, alignment: .center)
                    .padding(.top, 0)
                Image("\(recept.imageName)")
                    .resizable()
                    .aspectRatio(contentMode: .fit)
                    .scaleEffect(0.8)
                    .cornerRadius(5)
            }
            VStack {
                FormattedTextPrinter(text: "Main info", size: 34)
            }
            //            ScrollView {
            VStack(alignment: .leading, spacing: 0) {
                FormattedTextPrinter(text: "Name: \(recept.title)", size: 20)
                FormattedTextPrinter(text: "Description:", size: 20)
                FormattedTextPrinter(text: "\(recept.description)", size: 18)
                FormattedTextPrinter(text: "Ingredients", size: 20)
                ForEach(recept.ingredients, id: \.self) { i in
                    Text("• \(i)")
                        .frame(maxWidth: .infinity, alignment: .leading)
                        .padding(10)
                        .padding(.leading, 20)
                }
                FormattedTextPrinter(text: "Steps:", size: 20)
                CustomSteps(recept: recept)
            }
        }
    }
}


struct CustomSteps: View {
    var recept: Recipe
    var body: some View {
        ScrollView {
            ForEach(recept.steps, id: \.self) { i in
                
                NavigationLink(destination:  StepDesc(step: i)) {
                    FormattedTextPrinter(text: "\(i.id). Step", size: 30)
                    
                }
                .frame(width: 400, height: 100, alignment: .leading)
                .background(Color(hue: 22, saturation: 0.127, brightness: 0.465, opacity: 0.189))
                .cornerRadius(20)
                
            }
        }
    }
}


struct StepDesc: View {
    var step : Step
    var body: some View {
        VStack {
            Text("\(step.id). \(step.description)")
                .font(.system(size: 25))
                .fontWeight(.bold)
                .foregroundColor(Color.white)
                .padding(60)
                .frame(width: UIScreen.main.bounds.width, height: UIScreen.main.bounds.height, alignment: .topLeading)
        }
        
    }
}


struct CustomTitle: View {
    var body: some View {
        HStack {
            Text("Custom")
                .font(.system(size: 25, weight: .bold))
            Text("Title")
                .font(.system(size: 40, weight: .bold))
        }
    }
}

//struct ContentView_Previews: PreviewProvider {
//    static var previews: some View {
////        MenuView(Names:[Dishes.borsch, Dishes.chesar, Dishes.greekSalad, Dishes.pastaCarbonara, Dishes.sushi])
////            .preferredColorScheme(.dark)
////        ContentView()
//        StepDesc(step: Dishes.borsch.steps[0])
//            .preferredColorScheme(.dark)
//            .padding(0.0)
//            .previewDevice("iPhone 13")
//            .previewInterfaceOrientation(.portrait)
//    }
//}
//


//struct AnimatedGradientText: View {
//    var text: String
//    @State private var phase: CGFloat = 0.0
//
//    var body: some View {
//
//    }
//}

struct FormattedTextPrinter: View {
    var text: String
    var size: CGFloat
    var body: some View {
        Text(text)
            .font(.system(size: size))
            .multilineTextAlignment(.leading)
            .padding()
            .frame(width: UIScreen.main.bounds.width, alignment: .leading)
    }
}
