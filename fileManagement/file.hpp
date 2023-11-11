#include <fstream>
#include <string>
using namespace std;

class FileManager {
public:
    FileManager(const string& filename);
    bool write(const json& content);
    json read();
private:
    string filename;
};






