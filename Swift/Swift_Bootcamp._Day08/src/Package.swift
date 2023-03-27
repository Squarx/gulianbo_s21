// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Day08",
    dependencies: [
        .package(url: "https://github.com/Swinject/Swinject.git", from: "2.8.0")
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .executableTarget(
            name: "Task1",
            dependencies: ["Swinject"]),
        .executableTarget(
            name: "Learn",
            dependencies: ["Swinject"]),
        .executableTarget(
            name: "Task2",
            dependencies: ["Swinject"]),
        .testTarget(
            name: "Day08Tests",
            dependencies: ["Task1"]),
    ]
)
