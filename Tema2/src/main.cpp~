#include <iostream>
#include "Echipa.hpp"

int main() {
    // 1. Inițializare obiecte și afișare prin constructor
    std::cout << "Pasul 1: Inițializarea obiectelor.\n";
    
    // Obiecte alocate dinamic
    Echipa* echipa1 = new Echipa("Tigrii", 10, 50, 5);
    Echipa* echipa2 = new Echipa("Leii", 8, 30, 3);
    
    // Obiect alocat static
    Echipa echipa3("Vulturii", 12, 40, 4);

    // Afișăm informațiile despre echipe pentru a verifica inițializarea corectă
    echipa1->afiseazaInformatii();
    echipa2->afiseazaInformatii();
    echipa3.afiseazaInformatii();

    // 2. Supraincarcarea operatorului de atribuire (copiem echipa1 în echipa3)
    std::cout << "\nPasul 2: Supraincarcarea operatorului de atribuire (echipa3 = echipa1).\n";
    echipa3 = *echipa1; // Copiem echipa1 în echipa3
    echipa3.afiseazaInformatii();

    // 3. Adăugarea de puncte și actualizarea numărului de meciuri pentru echipe
    std::cout << "\nPasul 3: Adăugarea de puncte și actualizarea numărului de meciuri.\n";
    echipa1->adaugaPuncte(15);
    echipa2->adaugaPuncte(10);
    echipa3.adaugaPuncte(20);

    // Afișăm informațiile pentru a verifica modificările
    echipa1->afiseazaInformatii();
    echipa2->afiseazaInformatii();
    echipa3.afiseazaInformatii();

    // 4. Destructorul eliberează memoria alocată pentru atributele dinamice (cum ar fi nrMeciuri)
    // Destructorul va fi apelat automat la final pentru echipa3 (alocare statică).
    std::cout << "\nPasul 4: Destructorul eliberează memoria internă pentru nrMeciuri.\n";
    // Memoria pentru obiectele alocate dinamic va fi eliberată în pasul următor.

    // 5. Eliberăm memoria pentru obiectele alocate dinamic
    std::cout << "\nPasul 5: Eliberăm memoria pentru obiectele alocate dinamic.\n";
    delete echipa1;
    delete echipa2;

    std::cout << "\nFinalizarea programului.\n";

    return 0;
}
