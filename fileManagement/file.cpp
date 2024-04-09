#include "file.hpp"


File::File(const char *filename)
{
    strcpy(this->filename, filename);
}

bool File::write(Giocatore g [])
{
    ofstream file(this->filename);
    if (!file)
    {
        return false;
    }
    for(int i = 0; i< ngiocatori; i++){
        file << g[i].getNome() << " " << g[i].getPunteggio() << " " << g[i].getDataPunteggio() << "\n";
    }
    return true;
}

void File::read(Giocatore g[])
{
    ifstream file;
    file.open(this->filename);
    int count = 0;
    if (file.is_open())
    {
        char linea;
        while (!file.eof())
        {
            char nome[100];
            char punteggio[lpunteggio];
            char data[ldata];
            int countl = 0;
            while(file.get(linea) && linea != ' ' ){
                nome[countl] = linea;
                countl++;
            }

            countl = 0;
            while(file.get(linea) && linea != ' ' ){
                punteggio[countl] = linea;
                countl++;
            }
            countl = 0;
            while(file.get(linea) && linea != '\n' ){
                data[countl] = linea;
                countl++;
            }

            Giocatore gn(nome, atoi(punteggio), data);
            g[count] = gn;
            count++;
        }
        file.close();
    }
}
