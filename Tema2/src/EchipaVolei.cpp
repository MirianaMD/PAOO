#include "EchipaVolei.hpp"

// Constructor cu listă de inițializare
EchipaVolei::EchipaVolei(const std::string& nume, int nrJucatori, int puncte, int nrMeciuri, float inaltimeaMedie)
    : Echipa(nume, nrJucatori, puncte, nrMeciuri), inaltimeaMedie(inaltimeaMedie) {}

// Copy constructor
EchipaVolei::EchipaVolei(const EchipaVolei& other)
    : Echipa(other), inaltimeaMedie(other.inaltimeaMedie) {}

/*
// Move constructor
EchipaVolei::EchipaVolei(EchipaVolei&& other) noexcept
    : Echipa(std::move(other)), inaltimeaMedie(other.inaltimeaMedie) {
    other.inaltimeaMedie = 0.0;  // Resetăm valoarea pentru obiectul mutat
}
*/

// Destructor
EchipaVolei::~EchipaVolei() {
    std::cout << "Destructorul echipa volei :) "<< std::endl;
}

// Suprascrierea metodei de afișare a informațiilor
void EchipaVolei::afiseazaInformatii() const {
    Echipa::afiseazaInformatii();  // Apelăm metoda clasei de bază
    std::cout << "Inaltimea medie: " << inaltimeaMedie << " m" << std::endl;
}

// Suprascrierea operatorului de atribuire pentru copiere
EchipaVolei& EchipaVolei::operator=(const EchipaVolei& other) {
    if (this != &other) {
        Echipa::operator=(other);  // Apelăm operatorul de atribuire din clasa de bază
        inaltimeaMedie = other.inaltimeaMedie;  // Copiem atributul specific clasei derivate
    }
    return *this;
}

/*
// Suprascrierea operatorului de atribuire pentru mutare
EchipaVolei& EchipaVolei::operator=(EchipaVolei&& other) noexcept {
    if (this != &other) {
        Echipa::operator=(std::move(other));  // Apelăm operatorul de atribuire din clasa de bază pentru mutare
        inaltimeaMedie = other.inaltimeaMedie;  // Mutăm atributul specific clasei derivate
        other.inaltimeaMedie = 0.0;  // Resetăm valoarea pentru obiectul mutat
    }
    return *this;
}
*/

// Metodă specifică clasei derivate pentru a afișa numele echipei și înălțimea medie
void EchipaVolei::afiseazaNumeInaltime() const {
    std::cout << "Nume echipă: " << getNume() << ", Inaltimea medie: " << inaltimeaMedie << " m" << std::endl;
}

// Getter pentru atributul specific clasei derivate
float EchipaVolei::getInaltimeaMedie() const {
    return inaltimeaMedie;
}
