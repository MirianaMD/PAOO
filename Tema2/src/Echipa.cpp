#include "Echipa.hpp"

// Constructorul cu listă de inițializare
Echipa::Echipa(const std::string& nume, int nrJucatori, int puncte, int nrMeciuri)
    : nume(nume), nrJucatori(nrJucatori), puncte(puncte) {
    this->nrMeciuri = new int(nrMeciuri); // alocare dinamică pe heap pentru nrMeciuri
    std::cout << "Constructor: Echipa \"" << nume << "\" cu " << nrJucatori
              << " jucatori și " << puncte << " puncte in " << *this->nrMeciuri << " meciuri." << std::endl;
}

// copy constructor
Echipa::Echipa(const Echipa& other)
    : nume(other.nume), nrJucatori(other.nrJucatori), puncte(other.puncte) {
    std::cout << "Copy constructorul: Copiem echipa \"" << other.nume << "\"." << std::endl;
    nrMeciuri = new int(*other.nrMeciuri); // alocare și copierea valorii
    
}

// move constructor
Echipa::Echipa(Echipa&& other) noexcept
    : nume(std::move(other.nume)), nrJucatori(other.nrJucatori), puncte(other.puncte), nrMeciuri(other.nrMeciuri) {
    std::cout << "Constructor de mutare: Mutăm echipa \"" << nume << "\"." << std::endl;
    other.nrMeciuri = nullptr; // Nulling out the pointer to the temporary data
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

// Operator de atribuire pentru mutare
Echipa& Echipa::operator=(Echipa&& other) noexcept {
    if (this != &other) {
        delete nrMeciuri;
        nume = std::move(other.nume);
        nrJucatori = other.nrJucatori;
        puncte = other.puncte;
        nrMeciuri = other.nrMeciuri;
        other.nrMeciuri = nullptr;
    }
    return *this;
}

// Destructorul
Echipa::~Echipa() {
    if(nrMeciuri != nullptr){
    std::cout << "Destructor: Eliberăm memoria pentru echipa \"" << nume << "\"" << std::endl;
    delete nrMeciuri;
    }
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
              << puncte << " puncte în " << *nrMeciuri << " meciuri.\n";
}

// getter-uri
std::string Echipa::getNume() const { return nume; }
int Echipa::getNrJucatori() const { return nrJucatori; }
int Echipa::getNrMeciuri() const { return *nrMeciuri; }
int Echipa::getPuncte() const { return puncte; }
