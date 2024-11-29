#ifndef ECHIPA_HPP
#define ECHIPA_HPP

#include <string>
#include <iostream>
#include <memory>
#include <mutex>

class Echipa {
private:
    std::string nume;
    int nrJucatori;
    int puncte;
    std::unique_ptr<int> nrMeciuri; // Pointer unic pentru gestionarea nrMeciuri
    mutable std::mutex mtx;         // Mutex pentru sincronizare

public:
    // Constructorul cu parametri
    Echipa(const std::string& nume = "Necunoscut", int nrJucatori = 0, int puncte = 0, int nrMeciuri = 0);

    // Copy constructor
    Echipa(const Echipa& other);

    // Move constructor
    Echipa(Echipa&& other) noexcept;

    // Destructor
    virtual ~Echipa();

    // Copy assignment operator
    Echipa& operator=(const Echipa& other);

    // Move assignment operator
    Echipa& operator=(Echipa&& other) noexcept;

    // Adăugare puncte (thread-safe)
    void adaugaPuncte(int puncte);

    // Afișare informații
    virtual void afiseazaInformatii() const;

    // Getter pentru acces protejat
    std::string getNume() const;
    int getNrJucatori() const;
    int getNrMeciuri() const;
    int getPuncte() const;
};

#endif // ECHIPA_HPP
