//
//  main.swift
//  datasamples
//

import Foundation

mapIntToString()
filterNotZero()


func mapIntToString() {
    let intList = [1, 2, 3, 4]
    let stringList = intList.map { (ch) -> String in
        return String(ch)
    }
    print(stringList)
}

func filterNotZero() {
    let list = [1, 0, 0 , 0 , 0]
    let notZeroList = list.filter { (ch) -> Bool in
        return ch != 0
    }
    print(notZeroList)
}
