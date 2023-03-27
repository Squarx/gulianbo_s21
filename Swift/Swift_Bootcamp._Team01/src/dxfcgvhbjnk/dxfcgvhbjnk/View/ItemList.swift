//
//  Content3View.swift
//  dxfcgvhbjnk
//
//  Created by Gulian Boris on 3/25/23.
//

import Foundation
import SwiftUI
import RealmSwift
struct ItemListView: View {
//    var dishes : [Recipe] = load("data.json")
    //@State
    
    @ObservedRealmObject var group: Group
    var body: some View {
        NavigationView {
            List {
                ForEach(group.items) { item in
                    ItemRow(item: item)
                }
                .onMove(perform: $group.items.move)
                .onDelete(perform: $group.items.remove)
            }
            .listStyle(GroupedListStyle())
            .navigationBarTitle("Items", displayMode: .large)
            .navigationBarBackButtonHidden(true)
            .navigationBarItems(trailing: EditButton())
            .toolbar {
                ToolbarItem(placement: .bottomBar) {
                    Button {
                        $group.items.append(Item())
                    } label: {
                        Image(systemName: "plus")
                    }.frame(maxWidth: .infinity, alignment: .trailing)
                }
            }
        }
    }
}


struct ItemRow: View {
    
    @ObservedRealmObject var item: Item
    
    var body: some View {
        // You can click an item in the list to navigate to an edit details screen.
        NavigationLink(destination: ItemDetailView(item: item)) {
            Text(item.name)
            if item.isFavorite {
                // If the user "favorited" the item, display a heart icon
                Image(systemName: "heart.fill")
            }
        }
    }
}


struct ItemListView_preview: PreviewProvider {
    static var previews: some View {
        ItemListView(group: Group())
    }
}

