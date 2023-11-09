#include "file.hpp"
using namespace std;


FileManager::FileManager(const string& filename):filename(filename) {
}

bool FileManager::write(const string& content) {
  ofstream file(filename);
  if (!file) {
    return false;
  }
  file << content;
  return true;
}

std::string FileManager::read() {
  ifstream file(filename);
  if (!file) {
    throw runtime_error("Unable to open file for reading");
  }
  string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
  return content;
}