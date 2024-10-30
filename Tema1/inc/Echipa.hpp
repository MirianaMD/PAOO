#ifndef ECHIPA_HPP
#define ECHIPA_HPP

#include <string>
#include <iostream>

class Echipa {
private:
    std::string nume;
    int nrJucatori;
    int puncte;
    int* nrMeciuri; // alocare pe heap pentru nrMeciuri

public:
    // Constructorul cu parametri și listă de inițializare
    Echipa(const std::string& nume = "Necunoscut", int nrJucatori = 0, int puncte = 0, int nrMeciuri = 0);

    // Supraincarcarea operatorului de atribuire
    Echipa& operator=(const Echipa& other);

    // Destructorul
    ~Echipa();

    // Metodă pentru adăugarea punctelor și afișarea informațiilor despre echipă
    void adaugaPuncte(int puncte);
    void afiseazaInformatii() const;
    
    // Getteri pentru a accesa valorile membrilor
    std::string getNume() const;
    int getNrJucatori() const;
    int getNrMeciuri() const;
    int getPuncte() const;
};

#endif // ECHIPA_HPP
