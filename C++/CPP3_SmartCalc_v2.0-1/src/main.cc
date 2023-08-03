//#include "consoleView.h"
#include "model/Calcmodel.h"

int main() {
  std::string str_1 = "(((9 - 2) ^ 3) mod 5 * (7 - 4)) + 12 / 4";
  s21::CalcModel t;
  //  s21::CreditModel m;
  //  s21::Controller c(&t, &m);
  //  auto r = t.GetDataGraph(-0.0001, 0.00001 ,str_1);
  // std::cout << t.GetResult(str_1, 0).first << "\n";
  std::cout << t.GetResult(str_1, 0).second << "\n";

  //  for(auto i: *r.second) {
  //    std::cout << i << std::endl;
  //  }
  return 0;
}
