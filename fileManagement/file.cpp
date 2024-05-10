#include "file.hpp"


File::File(char filename[])
{
    strcpy(this->filename, filename);
}

bool File::write(Giocatore g [], int l)
{
    ofstream file(this->filename);
    if (!file)
    {
        return false;
    }
    for(int i = 0; i< l; i++){
        file << g[i].getNome() << " " << g[i].getPunteggio() << " " << g[i].getDataPunteggio() << "\n";
    }
    return true;
}

int File::read(Giocatore g[])
{
    ifstream file;
    file.open(this->filename);

    int count = 0;
    if (file.is_open())
    {
        char linea;
        bool end = false;
        while (!file.eof() && !end)
        {
            char nome[100] = "";
            char punteggio[lpunteggio] = "";
            char data[ldata] = "";
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
            //leggo solo i primi 10
            if(count == ngiocatori) end = true;
        }
        file.close();
        return count;

    }
}
