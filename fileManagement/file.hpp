#include <iostream>
#include <fstream>
using namespace std;


class fileManagment {
  private:
      const string nameFile = "classifica.json";
      fstream file;
      void openFile();
  public:
      fileManagment() {
          openFile();
      }
      bool writeFile(string s);
};
