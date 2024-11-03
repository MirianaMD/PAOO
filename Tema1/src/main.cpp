#include <iostream>
#include "Echipa.hpp"

int main() {
    //Inițializare obiecte și afișare prin constructor
    std::cout << "Pasul 1: Inițializarea obiectelor.\n";
    
    Echipa* echipa1 = new Echipa("Tigrii", 10, 50, 5);
    Echipa* echipa2 = new Echipa("Leii", 8, 30, 3);
    Echipa* echipa3 = new Echipa("Vulturii", 12, 40, 4);

    // info
    echipa1->afiseazaInformatii();
    echipa2->afiseazaInformatii();
    echipa3->afiseazaInformatii();

    //Supraincarcarea operatorului de atribuire (copiem echipa1 în echipa3)
    std::cout << "\nSupraincarcarea operatorului de atribuire (echipa3 = echipa1).\n";
    *echipa3 = *echipa1; // Copiem echipa1 în echipa3
    echipa3->afiseazaInformatii();

    //Adăugarea de puncte și actualizarea numărului de meciuri pentru echipe
    std::cout << "\nAdăugarea de puncte și actualizarea numărului de meciuri.\n";
    echipa1->adaugaPuncte(15);
    echipa2->adaugaPuncte(10);
    echipa3->adaugaPuncte(20);

    //Afișăm informațiile pentru a verifica modificările
    echipa1->afiseazaInformatii();
    echipa2->afiseazaInformatii();
    echipa3->afiseazaInformatii();

    //Destructorul eliberează memoria alocată pentru atributele dinamice (nrMeciuri)
    std::cout << "\nDestructorul eliberează memoria internă pentru nrMeciuri.\n";

    //Eliberăm memoria pentru obiectele alocate dinamic
    std::cout << "\nPasul 5: Eliberăm memoria pentru obiectele alocate dinamic.\n";
    delete echipa1;
    delete echipa2;
    delete echipa3;

    std::cout << "\nFinalizarea programului.\n";

    return 0;
}
