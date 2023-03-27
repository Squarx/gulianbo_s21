//
// Created by Gulian Boris on 3/13/23.
//

import Foundation

var scale = default_name(name: readLine()!)
var season = valid_seaon()
var current_temp = valid_temp()
var current_humidity = valid_humidity()

//print(current_temp, type(of: current_temp))
printer(scale: scale, season: season, temperature: current_temp, current_humidity: current_humidity)


func print_humidity(humidity: Double, season: String) {
    let (min_h, max_h) = season == "W" ? (30, 45) : (30, 60)
    print("The comfortable humidity is from \(min_h)% to \(max_h)%")
    if (humidity < Double(min_h) || humidity > Double(max_h)) {
        let tmp = humidity < Double(min_h) ? (String(format: "%.2f", (Double(min_h) - humidity)))  : String(format: "%.2f", (humidity - Double(max_h)))
        print("Please, make humidity \(humidity < Double(min_h) ? "lower" : "higher") by \(tmp)%.")
    } else {
        print("The humidity is comfortable")
    }
}

func valid_humidity() -> Double {
    if let input = readLine(), let doubleInput = Double(input), doubleInput >= 0, doubleInput <= 100 {
        return doubleInput
    } else {
        print("Incorrect input. Enter a valid humidity: ( 0-100 %)")
        return valid_humidity()
    }
}
func printer(scale: String, season: String, temperature: Double, current_humidity: Double) {
    var real_temp = 0.0
//    var temp_str = ""
    var (min_tmp, max_tmp) = season == "W" ? (20.0, 22.0) : (22.0, 25.0)
    var sign = "˚C"
    if (scale == "Kelvin") {
        real_temp = temperature + 273; min_tmp += 273; max_tmp += 273
//        temp_str = String(real_temp);
        sign = "K"
    } else if (scale == "Fahrenheit") {
        real_temp = temperature * 1.8 + 32; min_tmp = min_tmp * 1.8 + 32; max_tmp = max_tmp * 1.8 + 32;
        sign = "˚F"
//        temp_str = String(real_temp)
    } else {
        real_temp = temperature
//        temp_str = String(real_temp)
    }
    print("The temperature is \(real_temp) \(sign)")
    print("The comfortable temperature is from \(min_tmp) to \(max_tmp) \(sign).")
    if (real_temp < min_tmp || real_temp > max_tmp) {
        let tmp = real_temp < min_tmp ? (String(format: "%.2f", (min_tmp - real_temp)))  : String(format: "%.2f", (real_temp - max_tmp))
        print("Please, make it \(real_temp < min_tmp ? "warmer" : "cooler") by \(tmp) \(sign).")
    } else {
        print("Fine")
    }
    print_humidity(humidity: current_humidity, season: season)
}

func valid_temp() -> Double {
    if let input = readLine(), let doubleInput = Double(input) {
        return doubleInput
    } else {
        print("Incorrect input. Enter a temperature:")
        return valid_temp()
    }
}

func default_name(name: String) -> String {
    ["Celsius", "Kelvin", "Fahrenheit"].contains(name) ? name : "Celsius"
}

func valid_seaon() -> String {
    var season = readLine()!
    if (["W", "S"].contains(season)) {
    } else {
        print("Ivalid season (not W or S)")
        season = valid_seaon()
    }
    return season
}