#include <string>
using namespace std;

class Classifica {
public:
    void add_player(char name[], int score);
    void update();
    void getClassification();
private:
    char classification[];
};