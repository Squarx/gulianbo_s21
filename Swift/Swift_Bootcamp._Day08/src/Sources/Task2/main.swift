import Foundation
import Swinject

// Класс данных
class FootballMatchResult {
    var homeTeam: String
    var awayTeam: String
    var homeScore: Int
    var awayScore: Int
    
    init(homeTeam: String, awayTeam: String, homeScore: Int, awayScore: Int) {
        self.homeTeam = homeTeam
        self.awayTeam = awayTeam
        self.homeScore = homeScore
        self.awayScore = awayScore
    }
}

// Заглушка для сервиса сохранения данных в базу
class DbService {
    func saveFootballMatchResult(_ result: FootballMatchResult) {
        print("Data was saved in table")
        print("Result:\n\tMatch\(result.homeTeam)vs\(result.awayTeam)")
        print("\t\t\t\(result.homeScore) : \(result.awayScore)")
    
    }
}

// Заглушка для сервиса сетевых запросов
class NetworkService {
    let apiKey: String
    
    init(apiKey: String) {
        self.apiKey = apiKey
        print("API key: \(apiKey)")
    }
    
    func callApi() -> FootballMatchResult {
        return FootballMatchResult(homeTeam: "Real Madrid", awayTeam: "Barcelona", homeScore: 3, awayScore: 1)
    }
}

// Контроллер
class Controller {
    let networkService: NetworkService
    let dbService: DbService
    
    init(networkService: NetworkService, dbService: DbService) {
        self.networkService = networkService
        self.dbService = dbService
    }
    
    func fetchDataAndSave() {
        let result = networkService.callApi()
        print(result)
        dbService.saveFootballMatchResult(result)
    }
}

// Функция создания контейнера для inject объектов
func createContainer() -> Container {
    let container = Container()
    
    container.register(NetworkService.self) { r in
        let apiKey = UUID().uuidString
        return NetworkService(apiKey: apiKey)
    }.inObjectScope(.container)
    
    container.register(DbService.self) { _ in DbService() }
    
    container.register(Controller.self) { r in
        Controller(networkService: r.resolve(NetworkService.self)!, dbService: r.resolve(DbService.self)!)
    }
    
    return container
}

// Создание контейнера и инжект объектов в контроллер
let container = createContainer()
let controller = container.resolve(Controller.self)!

// Запуск контроллера
controller.fetchDataAndSave()

// Пересоздание NetworkService и Controller
let newContainer = createContainer()
let newController = newContainer.resolve(Controller.self)!

// Запуск нового контроллера с обновленным API ключом
newController.fetchDataAndSave()
