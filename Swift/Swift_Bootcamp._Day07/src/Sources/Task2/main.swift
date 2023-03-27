import Foundation

func callPublicFlightAPI(options: (app_id: String, app_key: String)) {
    let url = URL(string: "https://api.schiphol.nl/public-flights/flights")!

    var request = URLRequest(url: url)
    request.httpMethod = "GET"
    request.addValue("application/json", forHTTPHeaderField: "Accept")
    request.addValue("v4", forHTTPHeaderField: "Resourceversion")
    request.addValue(options.app_id, forHTTPHeaderField: "app_id")
    request.addValue(options.app_key, forHTTPHeaderField: "app_key")
    print("request: \(request)")
    let task = URLSession.shared.dataTask(with: request) { data, response, error in
        guard let data = data,
              let httpResponse = response as? HTTPURLResponse,
              error == nil,
              httpResponse.statusCode == 200
                else {
            print("Oops something went wrong")
            if let error = error {
                print(error.localizedDescription)
            }
            return
        }

        do {
            let flightList = try JSONDecoder().decode(FlightList.self, from: data)
            print("found \(flightList.flights.count) flights.")
            for flight in flightList.flights {
                print("Found flight with name: \(flight.flightName) scheduled on: \(flight.scheduleDate) at \(flight.scheduleTime)")
            }
        } catch let error {
            print("Oops something went wrong")
            print(error.localizedDescription)
        }
    }

    task.resume()
}

struct FlightList: Decodable {
    let flights: [Flight]
}

struct Flight: Decodable {
    let flightName: String
    let scheduleDate: String
    let scheduleTime: String
}

//let arguments = CommandLine.arguments
func main() {
    let options = (app_id: "1f180f30", app_key: "95c479567454a8896b434f1251e0938c")
    callPublicFlightAPI(options: options)
}
main()
dispatchMain()


