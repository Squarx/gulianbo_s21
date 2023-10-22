#include "file_reader.h"

namespace s21 {

void FileReader::SetFilePath(const std::string& file_path) {
  file_path_ = file_path;
}

Scene FileReader::ReadScene() {
  figure_.ClearFigure();
  std::string line{};
  std::ifstream in(file_path_);
  scene.ClearScene();

  if (in.is_open()) {
    while (std::getline(in, line)) {
      strategy_ = SolverStrategy::getInstance(line);

      if (!strategy_) {
        continue;
      }

      strategy_->Parce(line, figure_);
    }

    in.close();
  } else {
    throw std::runtime_error("Unable to open file: " + std::string(file_path_));
  }

  scene.AddFigure(figure_);

  return scene;
}
}  // namespace s21
