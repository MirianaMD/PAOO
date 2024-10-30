#include "Echipa.hpp"

// Constructorul cu listă de inițializare
Echipa::Echipa(const std::string& nume, int nrJucatori, int puncte, int nrMeciuri)
    : nume(nume), nrJucatori(nrJucatori), puncte(puncte) {
    this->nrMeciuri = new int(nrMeciuri); // alocare dinamică pe heap pentru nrMeciuri
    std::cout << "Constructor: Echipa \"" << nume << "\" cu " << nrJucatori
              << " jucatori și " << *this->nrMeciuri << " meciuri." << std::endl;
}

// Operatorul de atribuire
Echipa& Echipa::operator=(const Echipa& other) {
    if (this != &other) {
        std::cout << "Operatorul de atribuire: Copiem datele din echipa \"" 
                  << other.nume << "\" in echipa \"" << nume << "\"" << std::endl;

        // Eliberăm memoria existentă pentru nrMeciuri
        delete nrMeciuri;

        // Copiem membrii
        nume = other.nume;
        nrJucatori = other.nrJucatori;
        puncte = other.puncte;
        
        // Alocăm din nou memorie pentru nrMeciuri și copiem valoarea
        nrMeciuri = new int(*other.nrMeciuri);
    }
    return *this;
}

// Destructorul
Echipa::~Echipa() {
    std::cout << "Destructor: Eliberăm memoria pentru echipa \"" << nume << "\"" << std::endl;
    delete nrMeciuri;
}

// Metodă pentru a adăuga puncte la total
void Echipa::adaugaPuncte(int puncteNou) {
    std::cout << "Adăugăm " << puncteNou << " puncte pentru echipa \"" << nume << "\"" << std::endl;
    puncte += puncteNou;    // Actualizăm totalul punctelor
    (*nrMeciuri)++;         // Incrementăm numărul de meciuri
}

// Metodă pentru a afișa informațiile despre echipă
void Echipa::afiseazaInformatii() const {
    std::cout << "Echipa " << nume << " are " << nrJucatori << " jucatori, "
              << puncte << " puncte in " << *nrMeciuri << " meciuri." << std::endl;
}

// Getteri pentru acces la atribute
std::string Echipa::getNume() const {
    return nume;
}

int Echipa::getNrJucatori() const {
    return nrJucatori;
}

int Echipa::getNrMeciuri() const {
    return *nrMeciuri;
}

int Echipa::getPuncte() const {
    return puncte;
}
