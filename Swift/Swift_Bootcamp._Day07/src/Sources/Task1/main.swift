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
        let url = URL(string: "https://api.schiphol.nl/public-flights/flights")!

        var request = URLRequest(url: url)
        request.httpMethod = "GET"
        request.addValue("application/json", forHTTPHeaderField: "Accept")
        request.addValue("v4", forHTTPHeaderField: "Resourceversion")
        request.addValue("1f180f30", forHTTPHeaderField: "app_id")
        request.addValue("95c479567454a8896b434f1251e0938c", forHTTPHeaderField: "app_key")
        print("request: \(request)")
        let task = URLSession.shared.dataTask(with: request) { (data, response, error) in
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
main()
dispatchMain()
