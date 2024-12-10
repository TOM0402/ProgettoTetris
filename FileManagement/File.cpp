#include "File.hpp"


File::File(char filename[])
{
    strcpy(this->filename, filename);
}

bool File::write(Player g [], int l)
{
    ofstream file(this->filename);
    if (!file)
    {
        return false;
    }
    for(int i = 0; i< l; i++){
        file << g[i].getName() << " " << g[i].getPoints() << " " << g[i].getDatePoints() << "\n";
    }
    file.close();
    return true;
}

int File::read(Player g[])
{
    ifstream file;
    file.open(this->filename);
    
    if (!file.is_open()) {
        return 0;
    }

    int count = 0;
    if (file.is_open())
    {
        char line;
        bool end = false;
        while (!file.eof() && !end && count < num_players)
        {
            char name[len_name] = "";
            char points[len_points] = "";
            char date[len_date] = "";
            int count_len = 0;
            
            // Leggi il name
            while(file.get(line) && line != ' ' && count_len < len_name-1){
                name[count_len] = line;
                count_len++;
            }
            name[count_len] = '\0';  // Assicurati che la stringa sia terminata correttamente

            // Se il name è vuoto, salta questa iterazione
            if (strlen(name) == 0) {
                continue;
            }

            count_len = 0;
            // Leggi il points
            while(file.get(line) && line != ' ' && count_len < len_points-1){
                points[count_len] = line;
                count_len++;
            }
            points[count_len] = '\0';

            count_len = 0;
            // Leggi la date
            while(file.get(line) && line != '\n' && count_len < len_date-1){
                date[count_len] = line;
                count_len++;
            }
            date[count_len] = '\0';

            // Crea il giocatore solo se abbiamo letto tutti i campi correttamente
            if (strlen(name) > 0 && strlen(points) > 0 && strlen(date) > 0) {
                Player gn(name, atoi(points), date);
                g[count] = gn;
                count++;
            }
        }
    }
    file.close();
    return count;
}