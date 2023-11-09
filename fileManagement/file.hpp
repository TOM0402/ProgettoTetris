#include <string>
#include <fstream>
using namespace std;

class FileManager {
public:
    FileManager(const string& filename);
    bool write(const string& content);
    string read();
private:
    string filename;
};