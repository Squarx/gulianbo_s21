// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Day04",
    dependencies: [
    ],
    targets: [
        .executableTarget(
            name: "Task1",
            dependencies: []),
        .executableTarget(
            name: "Task3",
            dependencies: []),
        // Для второго надо открыть папку (drag'n drop) Task2/XcodeTask2 и там будет цель
//        .executableTarget(
//            name: "Task2",
//            dependencies: []),
]
)

