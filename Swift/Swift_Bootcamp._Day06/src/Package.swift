// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
        name: "Day06",
        dependencies: [
            .package(url: "https://github.com/ReactiveX/RxSwift.git", from: "6.0.0"),
            .package(url: "https://github.com/realm/realm-swift.git", .exact("10.33.0")),
            .package(url: "https://github.com/RxSwiftCommunity/RxRealm.git", from: "5.0.0")
            // Dependencies declare other packages that this package depends on.
            // .package(url: /* package url */, from: "1.0.0"),
        ],
        targets: [
            // Targets are the basic building blocks of a package. A target can define a module or a test suite.
            // Targets can depend on other targets in this package, and on products in packages this package depends on.
            .executableTarget(
                    name: "Day06",
                    dependencies: [
                        .product(name: "RealmSwift", package: "realm-swift"),
                        .product(name: "Realm", package: "realm-swift")
                    ]),
            .executableTarget(
                    name: "Task2",
                    dependencies: [
                        .product(name: "RealmSwift", package: "realm-swift"),
                                        .product(name: "RxRealm", package: "RxRealm"),
                                        .product(name: "RxSwift", package: "RxSwift"),
                                        .product(name: "RxCocoa", package: "RxSwift")
                    ]),

            .testTarget(
                    name: "Day06Tests",
                    dependencies: ["Day06"]),
        ]
)
