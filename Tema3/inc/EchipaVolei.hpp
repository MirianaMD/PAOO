#ifndef ECHIPAVOLEI_HPP
#define ECHIPAVOLEI_HPP

#include <string>
#include <iostream>
#include <memory> // pentru smart pointers
#include <mutex>  // pentru thread-safety
#include "Echipa.hpp"

class EchipaVolei : public Echipa {
private:
    std::shared_ptr<float> inaltimeaMedie; // Smart pointer pentru gestionarea resursei
    mutable std::mutex mtx; // Mutex pentru thread-safety

public:
    // Constructor cu listă de inițializare
    EchipaVolei(const std::string& nume = "Necunoscut", int nrJucatori = 0, int puncte = 0, int nrMeciuri = 0, float inaltimeaMedie = 0.0);

    // Copy constructor
    EchipaVolei(const EchipaVolei& other);

    // Move constructor
    EchipaVolei(EchipaVolei&& other) noexcept;

    // Destructor
    virtual ~EchipaVolei();

    // Suprascrierea metodei de afișare a informațiilor
    void afiseazaInformatii() const override;

    // Suprascrierea operatorului de atribuire pentru copiere
    EchipaVolei& operator=(const EchipaVolei& other);

    // Suprascrierea operatorului de atribuire pentru mutare
    EchipaVolei& operator=(EchipaVolei&& other) noexcept;

    // Metodă specifică clasei derivate pentru a afișa numele echipei și înălțimea medie
    void afiseazaNumeInaltime() const;

    // Getter thread-safe pentru înălțimea medie
    float getInaltimeaMedie() const;
};

#endif // ECHIPAVOLEI_HPP
