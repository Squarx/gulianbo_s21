//
// Created by Gulian Boris on 3/21/23.
//
import RxSwift
import RxCocoa
import Foundation
struct Sample {
    let id: Int
    let text: String
}


let firstCollection = Observable.of("first", "second", "third")
let firstCollectionMoreFive = Observable.of("firstt", "second", "thirdd")
print("Task1")
var secondCollection = filterCollection(firstCollection)
secondCollection.subscribe(onNext: {print($0)})
        .disposed(by: DisposeBag())
print("\nTask2")
var thirdCollection = findFirstStartingWithTh(firstCollection)
thirdCollection.subscribe(onSuccess: { print($0) })
        .disposed(by:DisposeBag())
print("\nTask3")
var bool1 = areAllStringsLongerThanFive(firstCollection)
bool1.subscribe(onNext: {print($0)})
    .disposed(by: DisposeBag())
var bool2 = areAllStringsLongerThanFive(firstCollectionMoreFive)
bool2.subscribe(onNext: {print($0)})
        .disposed(by: DisposeBag())

print("\nTask4")
var bool3 = areOneStringLongerThanFive(firstCollection)
bool3.subscribe(onNext: {print($0)})
        .disposed(by: DisposeBag())
print("\nTask5")
var fourthCollection: Observable<String?> = Observable.of("first", "second", "third", nil)
var bool4 = areNoStringEqualNil(fourthCollection)
bool4.subscribe(onNext: {print($0)})
        .disposed(by: DisposeBag())
fourthCollection = Observable.of("first", "second", "third")
bool4 = areNoStringEqualNil(fourthCollection)
bool4.subscribe(onNext: {print($0)})
        .disposed(by: DisposeBag())
print("\nTask6")
var fifthCollection: Observable<String?> = Observable.of("first", "second", "third", nil)
var bool5 = totalLengthOfStrings(fourthCollection)
bool5.subscribe(onNext: {print($0)})
        .disposed(by: DisposeBag())
print("\nTask7")
fifthCollection = Observable.of("first", "second", "third", nil)
var bool6 = countNonNilStrings(fourthCollection)
bool6.subscribe(onSuccess: {print($0)})
        .disposed(by: DisposeBag())

print("\nTask8")
let tmpCollection: Observable<Sample?> = Observable.of(
        Sample(id: 1, text: "some text"),
        Sample(id: 1, text: "any text"),
        Sample(id: 2, text: "more text"),
        Sample(id: 2, text: "other text"),
        Sample(id: 3, text: "too text")
)
//var sevenCollection = Observable.of("first", "second", "third", nil)
var bool7 = getTexts(tmpCollection)
bool7.subscribe(onSuccess: {print($0)})
        .disposed(by: DisposeBag())
print("\nTask9")
var tmp1Collection: Observable<Sample?> = Observable.of(
        Sample(id: 1, text: "some text"),
        Sample(id: 1, text: "any text"),
        Sample(id: 2, text: "more text"),
        Sample(id: 2, text: "other text"),
        Sample(id: 3, text: "too text")
)

var tt = groupById(tmp1Collection)

tt.subscribe(onSuccess: { groupedObservables in
            for group in groupedObservables {
                let groupId = group.key
                print("Group ID: \(groupId) И я не понимаю как дальше раскрыть значения")
                group.toArray()
                        .subscribe(onSuccess: { samples in
                            for sample in samples {
                                print("\(groupId), \(sample.text)")
                            }
                        })
                        .disposed(by: DisposeBag())
            }
        })
        .disposed(by: DisposeBag())
print("\nTask10")
func groupAndCountById(_ input: [Sample]) -> [Pair] {
    return input.reduce(into: [:]) { counts, sample in
                counts[sample.id, default: 0] += 1
            }
            .map { Pair(key: $0, value: $1) }
}

//
struct Pair {
    let key: Int
    let value: Int
}

let samples = [
    Sample(id: 1, text: "some text"),
    Sample(id: 1, text: "any text"),
    Sample(id: 2, text: "more text"),
    Sample(id: 2, text: "other text"),
    Sample(id: 3, text: "too text")
]

let counts = groupAndCountById(samples)
counts.forEach {
    print($0)
}
/**

 - Parameter collection:
 - Returns: All items of collection contains "e"
 */
func filterCollection(_ collection: Observable<String>) -> Observable<String> {
    collection.filter { $0.contains("e") }
}

/**

 - Parameter collection:
 - Returns: first value of collection starts with "th"
 */
func findFirstStartingWithTh(_ collection: Observable<String>) -> Single<String> {
    return collection
            .filter({ $0.starts(with: "th") })
            .asSingle()
}
/**

 - Parameter collection:
 - Returns: Bool all strings > 5 character
 */
func areAllStringsLongerThanFive(_ collection: Observable<String>) -> Observable<Bool> {
    return collection.map { $0.count > 5 }.reduce(true) { $0 && $1 }
}
/**

 - Parameter collection:
 - Returns: Bool At least one string > 5 character
 */
func areOneStringLongerThanFive(_ collection: Observable<String>) -> Observable<Bool> {
    return collection.map { $0.count > 5 }.reduce(true) { $0 || $1 }
}


/**
 - Parameter collection:
 - Returns: Bool No string == nil => True
 */
func areNoStringEqualNil(_ collection: Observable<String?>) -> Observable<Bool> {
    return collection.map { $0 != nil }.reduce(true) { $0 && $1 }
}
/**

 - Parameter collection:
 - Returns: Int == len of all strings
 */
func totalLengthOfStrings(_ collection: Observable<String?>) -> Observable<Int> {
    return collection
            .filter { $0 != nil }
            .map { $0!.count }
            .reduce(0, accumulator: +)
}

/**

 - Parameter collection:
 - Returns: Int == len of all strings
 */
func countNonNilStrings(_ collection: Observable<String?>) -> Single<Int> {
    return collection
            .filter { $0 != nil }
            .map { _ in 1 }
            .toArray()
            .map { $0.reduce(0, +) }
}

func getTexts(_ collection: Observable<Sample?>) -> PrimitiveSequence<SingleTrait, [String]> {
    return collection
            .filter { $0 != nil }
            .map { $0!.text }
            .toArray()
            .map { $0.compactMap { $0 } }
}


func groupById(_ collection: Observable<Sample?>) -> Single<[GroupedObservable<Int, Sample>]> {
    return collection
            .compactMap { $0 } // удаляем nil
            .groupBy { $0.id } // группируем по id
            .asObservable()
            .toArray() // преобразуем в массив

}


//
//func groupByIdWithCnt(_ collection: [Sample]) -> [Pair] {
//    var counts: [Int: Int] = [:]
//    for sample in collection {
//        counts[sample.id, default: 0] += 1
//    }
//    return counts.map { Pair(key: $0.key, value: $0.value) }
//}