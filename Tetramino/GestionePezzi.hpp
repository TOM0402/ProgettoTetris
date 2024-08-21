#ifndef PROGETTOTETRIS_GESTIONEPEZZI_HPP
#define PROGETTOTETRIS_GESTIONEPEZZI_HPP
#include "../Tetramino/Tetramino.hpp"

struct list{
    Tetramino t();
    list *next;
};
typedef list *p_list;


class GestionePezzi{
protected:
    p_list pezzi;
    void generateRandom();
    p_list append(Tetramino t);
    p_list remove();
};


#endif //PROGETTOTETRIS_GESTIONEPEZZI_HPP
