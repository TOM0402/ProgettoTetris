//
// Created by tommaso on 11/03/24.
//
#include <iostream>
#include "Giocatore.hpp"
using namespace std;
int main() {
    // Create a new Giocatore object with name "Alice" and score 0
    Giocatore alice("Alice");
    cout<<alice.getNome()<<" ";
    cout<<alice.getPunteggio()<<" ";
    // Set the name and score of the object
    alice.setNome("Bob");
    alice.setPunteggio(100);

    // Print the name and score of the object
    std::cout << "Name: " << alice.getNome() << ", Score: " << alice.getPunteggio() << std::endl;
    std::cout << "Data del punteggio: " << alice.getDataPunteggio()<<endl;

    return 0;
}