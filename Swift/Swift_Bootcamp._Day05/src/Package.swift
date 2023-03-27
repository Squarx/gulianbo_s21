// swift-tools-version:5.5

import PackageDescription

let package = Package(
    name: "Day05",
    dependencies: [
        .package(url: "https://github.com/ReactiveX/RxSwift.git", from: "5.1.0")
    ],
    targets: [
        .executableTarget(
            name: "ex01",
            dependencies: [
                .product(name: "RxSwift", package: "RxSwift"),
                .product(name: "RxCocoa", package: "RxSwift"),
            ]),
        .executableTarget(
                name: "Learn",
                dependencies: [
                    .product(name: "RxSwift", package: "RxSwift"),
                    .product(name: "RxCocoa", package: "RxSwift"),
                ])

    ]
)
