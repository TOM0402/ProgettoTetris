#include <iostream>
#include "fileManagement/file.hpp"
using namespace std;

int main() {

  FileManager fm("classifica.json");
  char s []= "Prova classifica!";
  if(fm.write(s)){
    cout << "File written successfully!" << endl;
  }else{
    cout << "Error writing file." << endl;
  }

  cout<<fm.read();

  return 0;
}

