#include "Echipa.hpp"

// Constructorul cu listă de inițializare
Echipa::Echipa(const std::string& nume, int nrJucatori, int puncte, int nrMeciuri)
    : nume(nume), nrJucatori(nrJucatori), puncte(puncte), nrMeciuri(std::make_unique<int>(nrMeciuri)) {}

// Copy constructor
Echipa::Echipa(const Echipa& other) 
    : nume(other.nume), nrJucatori(other.nrJucatori), puncte(other.puncte), nrMeciuri(std::make_unique<int>(*other.nrMeciuri)) {}

// Move constructor
Echipa::Echipa(Echipa&& other) noexcept
    : nume(std::move(other.nume)), nrJucatori(other.nrJucatori), puncte(other.puncte), nrMeciuri(std::move(other.nrMeciuri)) {}

// Destructor
Echipa::~Echipa() = default;

// Copy assignment operator
Echipa& Echipa::operator=(const Echipa& other) {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(mtx); // Sincronizare
        nume = other.nume;
        nrJucatori = other.nrJucatori;
        puncte = other.puncte;
        nrMeciuri = std::make_unique<int>(*other.nrMeciuri);
    }
    return *this;
}

// Move assignment operator
Echipa& Echipa::operator=(Echipa&& other) noexcept {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(mtx); // Sincronizare
        nume = std::move(other.nume);
        nrJucatori = other.nrJucatori;
        puncte = other.puncte;
        nrMeciuri = std::move(other.nrMeciuri);
    }
    return *this;
}

// Metodă pentru adăugarea punctelor
void Echipa::adaugaPuncte(int puncteNou) {
    std::lock_guard<std::mutex> lock(mtx); // Protejăm accesul la resurse
    puncte += puncteNou;
    (*nrMeciuri)++;
}

// Metodă pentru afișarea informațiilor
void Echipa::afiseazaInformatii() const {
    std::lock_guard<std::mutex> lock(mtx); // Protejăm accesul la resurse
    std::cout << "Echipa " << nume << " are " << nrJucatori << " jucatori, "
              << puncte << " puncte în " << *nrMeciuri << " meciuri.\n";
}

// Getteri
std::string Echipa::getNume() const { return nume; }
int Echipa::getNrJucatori() const { return nrJucatori; }
int Echipa::getNrMeciuri() const { return *nrMeciuri; }
int Echipa::getPuncte() const { return puncte; }
