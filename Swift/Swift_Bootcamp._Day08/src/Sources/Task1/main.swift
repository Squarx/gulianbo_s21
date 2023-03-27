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

// Заглушка для сервиса сетевых запросов
class NetworkService {
    func getFootballMatchResult() -> FootballMatchResult {
        return FootballMatchResult(homeTeam: "Real Madrid", awayTeam: "Barcelona", homeScore: 3, awayScore: 1)
    }
}

// Заглушка для сервиса сохранения данных в базу
class DbService {
    func saveFootballMatchResult(_ result: FootballMatchResult) {
        print("Data was saved in table")
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
        let result = networkService.getFootballMatchResult()
        print("Result:\n\tMatch\(result.homeTeam)vs\(result.awayTeam)")
        print("\t\t\t\(result.homeScore) : \(result.awayScore)")
        dbService.saveFootballMatchResult(result)
    }
}

// Функция создания контейнера для inject объектов
func createContainer() -> Container {
    let container = Container()
    
    container.register(NetworkService.self) { _ in NetworkService() }
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

/*
 Этот код использует Dependency Injection (DI), который позволяет легко изменять зависимости между объектами приложения, не требуя жесткой привязки между ними. DI позволяет создавать более гибкое и тестируемое приложение.

 Класс FootballMatchResult описывает модель данных о результате футбольного матча. У класса есть свойства homeTeam, awayTeam, homeScore и awayScore, которые хранят информацию о командах и счете. В инициализаторе класса эти свойства инициализируются значениями, переданными в качестве аргументов.

 Класс NetworkService представляет собой заглушку для сервиса сетевых запросов. У него есть метод getFootballMatchResult(), который возвращает экземпляр класса FootballMatchResult с жестко заданными значениями.

 Класс DbService представляет собой заглушку для сервиса сохранения данных в базу данных. У него есть метод saveFootballMatchResult(), который принимает объект типа FootballMatchResult и печатает сообщение о сохранении данных в таблице и значения переданного объекта.

 Класс Controller связывает объекты NetworkService и DbService вместе. Он имеет свойства networkService и dbService, которые являются зависимостями для контроллера. Контроллер имеет метод fetchDataAndSave(), который использует метод getFootballMatchResult() из networkService для получения данных о результате футбольного матча и затем передает их в метод saveFootballMatchResult() из dbService для сохранения.

 Функция createContainer() создает контейнер Swinject, который используется для внедрения зависимостей. Внутри этой функции происходит регистрация трех классов - NetworkService, DbService и Controller. Контроллер зарегистрирован с зависимостями networkService и dbService, которые разрешаются из контейнера.

 В конце программы создается экземпляр контейнера, используя createContainer(), и разрешается экземпляр контроллера из контейнера. Затем вызывается метод fetchDataAndSave() на экземпляре контроллера, который вызывает методы getFootballMatchResult() и saveFootballMatchResult() из networkService и dbService соответственно, и выводит данные о результате матча в консоль.
 */
