#ifndef ECHIPA_HPP
#define ECHIPA_HPP

#include <string>
#include <iostream>

class Echipa {
private:
    std::string nume;
    int nrJucatori;
    int puncte;
    int* nrMeciuri;

public:
    // Constructorul cu parametri și listă de inițializare
    Echipa(const std::string& nume = "Necunoscut", int nrJucatori = 0, int puncte = 0, int nrMeciuri = 0);

    // copy constructorul
    Echipa(const Echipa& other);

    // move constructor
    Echipa(Echipa&& other) noexcept;

    // Operatorul de atribuire pentru mutare
    Echipa& operator=(Echipa&& other) noexcept;

    // Destructorul
    virtual ~Echipa();
    
    // Supraincarcarea operatorului de atribuire
    Echipa& operator=(const Echipa& other);

    // Metodă pentru adăugarea punctelor și afișarea informațiilor despre echipă
    void adaugaPuncte(int puncte);
    virtual void afiseazaInformatii() const;
    
    // Getteri protejați pentru acces din clase derivate
    std::string getNume() const;
    int getNrJucatori() const;
    int getNrMeciuri() const;
    int getPuncte() const;
};

#endif // ECHIPA_HPP
