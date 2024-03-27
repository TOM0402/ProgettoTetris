#include "file.hpp"

File::File(const char* filename) {
    strcpy(this->filename, filename);
}

bool File::write(Giocatore g) {
    ofstream file(this->filename,std::ios::app);
    if (!file) {
        return false;
    }
    file << g.getNome() << " " << g.getPunteggio() << " " << g.getDataPunteggio()<<"\n";
    return true;
}

void File::read(Giocatore g[]) {
    ifstream file;
    file.open(this->filename);
    int count = 0;
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            char nome[100];
            int punteggio;
            char data[ldata];
            sscanf(linea.c_str(), "%s %d %s", nome, &punteggio, data);
            Giocatore gn (nome, punteggio, data);
            g[count] = gn;
            count++;
        }
        file.close();
    }
}

