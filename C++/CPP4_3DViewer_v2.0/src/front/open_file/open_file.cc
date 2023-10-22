#include "../front.h"

std::string Front::OpenFile() {
  QString filename = QFileDialog::getOpenFileName(
      this, "Open oject file", QDir::currentPath(), "Object files (*.obj)");

  return filename.toStdString();
}
