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
    file.close();
    return true;
}

int File::read(Giocatore g[])
{
    ifstream file;
    file.open(this->filename);
    
    if (!file.is_open()) {
        return 0;
    }

    int count = 0;
    if (file.is_open())
    {
        char linea;
        bool end = false;
        while (!file.eof() && !end && count < ngiocatori)
        {
            char nome[lnome] = "";
            char punteggio[lpunteggio] = "";
            char data[ldata] = "";
            int countl = 0;
            
            // Leggi il nome
            while(file.get(linea) && linea != ' ' && countl < lnome-1){
                nome[countl] = linea;
                countl++;
            }
            nome[countl] = '\0';  // Assicurati che la stringa sia terminata correttamente

            // Se il nome è vuoto, salta questa iterazione
            if (strlen(nome) == 0) {
                continue;
            }

            countl = 0;
            // Leggi il punteggio
            while(file.get(linea) && linea != ' ' && countl < lpunteggio-1){
                punteggio[countl] = linea;
                countl++;
            }
            punteggio[countl] = '\0';

            countl = 0;
            // Leggi la data
            while(file.get(linea) && linea != '\n' && countl < ldata-1){
                data[countl] = linea;
                countl++;
            }
            data[countl] = '\0';

            // Crea il giocatore solo se abbiamo letto tutti i campi correttamente
            if (strlen(nome) > 0 && strlen(punteggio) > 0 && strlen(data) > 0) {
                Giocatore gn(nome, atoi(punteggio), data);
                g[count] = gn;
                count++;
            }
        }
    }
    file.close();
    return count;
}