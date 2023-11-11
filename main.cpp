#include <iostream>
#include "fileManagement/file.hpp"
using namespace std;

int main() {
  FileManager fileManager("example.json");
  json content {
    {"name", "John Doe"},
    {"age", 30},
    {"city", "New York"}
  };

  bool result = fileManager.write(content);
  if (result) {
      cout << "Successfully written to file." << endl;
  } else {
      cout << "Failed to write to file." << endl;
  }
  try {
    json readContent = fileManager.read();
    cout << "Name: " << readContent["name"] << endl;
    cout << "Age: " << readContent["age"] << endl;
    cout << "City: " << readContent["city"] << endl;
  } catch (const runtime_error& e) {
      cout << "Error: " << e.what() << endl;
  }
  return 0;
}

