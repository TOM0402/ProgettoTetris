#include "file.hpp"
using namespace std;

void fileManagment::openFile() {
  file.open(nameFile);
}

bool fileManagment::writeFile(string s) {
  if (file.is_open()) {
      file << s;
      file.close();
      return true;
  } else {
      return false;
  }
}