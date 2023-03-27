let firstCollection = Observable.of("first", "second", "third")

struct Sample {
    let id: Int
    let text: String
}

let secondCollection = Observable.of(
        Sample(1, "some text"),
        Sample(1, "any text"),
        Sample(2, "more text"),
        Sample(2, "other text"),
        Sample(3, "too text")
)
