#ifndef INC_3D_VIEWER_SRC_BACKEND_FILE_READER_BASE_FILEREADER_H_
#define INC_3D_VIEWER_SRC_BACKEND_FILE_READER_BASE_FILEREADER_H_

#include <iostream>

#include "../scene/scene.h"
namespace s21 {

class BaseFileReader {
 public:
  virtual Scene ReadScene() = 0;
  virtual void SetFilePath(const std::string& path) = 0;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_FILE_READER_BASE_FILEREADER_H_
