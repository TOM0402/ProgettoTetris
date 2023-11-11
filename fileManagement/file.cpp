#include "file.hpp"
#include <json/json.h>

using namespace std;

FileManager::FileManager(const string& filename):filename(filename) {
}

bool FileManager::write(const json& content) {
 ofstream file(filename);
 if (!file) {
    return false;
 }
 file << content.dump(4);
 return true;
}

json FileManager::read() {
 ifstream file(filename);
 if (!file) {
    throw runtime_error("Unable to open file for reading");
 }
 string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
 return json::parse(content);
}