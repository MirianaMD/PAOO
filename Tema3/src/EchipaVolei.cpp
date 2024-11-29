#include "EchipaVolei.hpp"

// Constructor cu listă de inițializare
EchipaVolei::EchipaVolei(const std::string& nume, int nrJucatori, int puncte, int nrMeciuri, float inaltimeaMedie)
    : Echipa(nume, nrJucatori, puncte, nrMeciuri), inaltimeaMedie(std::make_shared<float>(inaltimeaMedie)) {}

// Copy constructor
EchipaVolei::EchipaVolei(const EchipaVolei& other)
    : Echipa(other), inaltimeaMedie(std::make_shared<float>(*other.inaltimeaMedie)) {}

// Move constructor
EchipaVolei::EchipaVolei(EchipaVolei&& other) noexcept
    : Echipa(std::move(other)), inaltimeaMedie(std::move(other.inaltimeaMedie)) {}

// Destructor
EchipaVolei::~EchipaVolei() {
    std::cout << "Destructorul echipei de volei este apelat pentru echipa \"" << getNume() << "\"" << std::endl;
}

// Suprascrierea metodei de afișare a informațiilor
void EchipaVolei::afiseazaInformatii() const {
    std::lock_guard<std::mutex> lock(mtx); // Protejăm accesul cu un mutex
    Echipa::afiseazaInformatii();          // Apelăm metoda clasei de bază
    std::cout << "Inaltimea medie: " << *inaltimeaMedie << " m" << std::endl;
}

// Suprascrierea operatorului de atribuire pentru copiere
EchipaVolei& EchipaVolei::operator=(const EchipaVolei& other) {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(mtx); // Thread-safe
        Echipa::operator=(other);             // Apelăm operatorul de atribuire din clasa de bază
        inaltimeaMedie = std::make_shared<float>(*other.inaltimeaMedie);
    }
    return *this;
}

// Suprascrierea operatorului de atribuire pentru mutare
EchipaVolei& EchipaVolei::operator=(EchipaVolei&& other) noexcept {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(mtx); // Thread-safe
        Echipa::operator=(std::move(other));  // Apelăm operatorul de atribuire din clasa de bază
        inaltimeaMedie = std::move(other.inaltimeaMedie);
    }
    return *this;
}

// Metodă specifică clasei derivate pentru a afișa numele echipei și înălțimea medie
void EchipaVolei::afiseazaNumeInaltime() const {
    std::lock_guard<std::mutex> lock(mtx); // Thread-safe
    std::cout << "Nume echipă: " << getNume() << ", Inaltimea medie: " << *inaltimeaMedie << " m" << std::endl;
}

// Getter thread-safe pentru înălțimea medie
float EchipaVolei::getInaltimeaMedie() const {
    std::lock_guard<std::mutex> lock(mtx); // Thread-safe
    return *inaltimeaMedie;
}
