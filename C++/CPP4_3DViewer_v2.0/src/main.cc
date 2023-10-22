#include <QApplication>

#include "backend/facade/facade.h"
#include "backend/solver/solver_strategy.h"
#include "backend/strategy/abstract_parcer.h"
#include "front/front.h"

std::shared_ptr<s21::AbstractParcer> s21::SolverStrategy::vertex_parcer_ =
    nullptr;
std::shared_ptr<s21::AbstractParcer> s21::SolverStrategy::facet_parcer_ =
    nullptr;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Facade facade{};
  s21::Controller controller{&facade};

  Front w{&controller};

  w.show();
  return a.exec();
}
