#ifndef INC_3D_VIEWER_SRC_BACKEND_FILE_READER_FILE_READER_H_
#define INC_3D_VIEWER_SRC_BACKEND_FILE_READER_FILE_READER_H_

#include <fstream>
#include <iomanip>
#include <memory>
#include <utility>

#include "../solver/solver_strategy.h"
#include "../strategy/abstract_parcer.h"
#include "../strategy/facets_parcer.h"
#include "base_filereader.h"

namespace s21 {

class FileReader : public BaseFileReader {
 public:
  FileReader() = default;

  explicit FileReader(std::string file_path)
      : file_path_(std::move(file_path)) {}

  void SetFilePath(const std::string& file_path) override;
  Scene ReadScene() override;
  Scene GetScene() { return scene; }

 private:
  Scene scene{};
  std::string file_path_;
  Figure figure_{};
  std::shared_ptr<AbstractParcer> strategy_{};
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_FILE_READER_FILE_READER_H_
