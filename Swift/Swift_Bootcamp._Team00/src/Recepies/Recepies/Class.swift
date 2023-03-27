//
//  Class.swift
//  Recepies
//
//  Created by Gulian Boris on 3/19/23.
//

import Foundation
import SwiftUI

struct Recipe: Identifiable, Decodable {
    let id: Int
    let title: String
    let imageName: String
    let description: String
    let ingredients: [String]
    let steps: [Step]
}

struct Step: Identifiable, Codable, Hashable {
    let id: Int
    let description: String
    let imageName: String?
}
