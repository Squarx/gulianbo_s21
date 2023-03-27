//
//  main.swift
//  Day7
//
//  Created by Gulian Boris on 3/22/23.
//
import Foundation


struct Flight: Codable {
    let id: String
    let airline: String
    let flightNumber: String
    let scheduledTime: Date
    let estimatedTime: Date?
    let gate: String?
    let status: String
    let destination: String
    let terminal: String
    let remarks: String?
}

struct FlightList: Codable {
    let flights: [Flight]
}

protocol IObjectService {
    var baseURL: URL { get }
    func fetchFlights(completion: @escaping (FlightList?, Error?) -> Void)
}

class ObjectService: IObjectService {
    let baseURL: URL
    
    init(baseURL: URL) {
        self.baseURL = baseURL
    }
    
    func fetchFlights(completion: @escaping (FlightList?, Error?) -> Void) {
        let url = baseURL.appendingPathComponent("flights")
        let task = URLSession.shared.dataTask(with: url) { (data, response, error) in
            if let error = error {
                completion(nil, error)
            } else if let data = data {
                do {
                    let decoder = JSONDecoder()
                    let flightList = try decoder.decode(FlightList.self, from: data)
                    completion(flightList, nil)
                } catch let error {
                    completion(nil, error)
                }
            }
        }
        task.resume()
    }
}
func main() {
let baseURL = URL(string: "https://api.schiphol.nl/public-flights/")!
let service = ObjectService(baseURL: baseURL)

service.fetchFlights { (flightList, error) in
    if let error = error {
        print("Error fetching flights: \(error)")
    } else if let flightList = flightList {
        print("Fetched \(flightList.flights.count) flights")
        // Do something with the flights data here
    }
}
}

