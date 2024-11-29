#include <iostream>
#include <memory>
#include "Echipa.hpp"
#include "EchipaVolei.hpp"

int main() {
    std::cout << "==== Exemplu cu std::unique_ptr ====\n";

    // Creăm o echipă folosind std::unique_ptr
    std::unique_ptr<Echipa> echipa1 = std::make_unique<Echipa>("Tigrii", 11, 25, 10);
    echipa1->afiseazaInformatii();

    // Adăugăm puncte echipei
    echipa1->adaugaPuncte(5);
    echipa1->afiseazaInformatii();

    // Mutăm ownership-ul echipei într-un alt unique_ptr
    std::unique_ptr<Echipa> echipa2 = std::move(echipa1);
    if (!echipa1) {
        std::cout << "echipa1 nu mai deține ownership-ul resursei.\n";
    }
    echipa2->afiseazaInformatii();

    std::cout << "\n==== Exemplu cu std::shared_ptr ====\n";

    // Creăm o echipă folosind std::shared_ptr
    std::shared_ptr<EchipaVolei> echipaVolei1 = std::make_shared<EchipaVolei>("Vulturii", 6, 20, 8, 1.85);
    echipaVolei1->afiseazaInformatii();

    // Partajăm ownership-ul echipei de volei
    std::shared_ptr<EchipaVolei> echipaVolei2 = echipaVolei1;
    std::cout << "Echipa Volei 1 este partajată cu Echipa Volei 2.\n";
    echipaVolei2->afiseazaNumeInaltime();

    // Adăugăm puncte echipei și observăm modificarea în ambele instanțe
    echipaVolei1->adaugaPuncte(10);
    std::cout << "\n==== După adăugarea punctelor ====\n";
    echipaVolei1->afiseazaInformatii();
    echipaVolei2->afiseazaInformatii();

    std::cout << "\n==== Exemplu cu polimorfism și std::unique_ptr ====\n";

    // Creăm un obiect de tip EchipaVolei folosind pointerul de bază Echipa
    std::unique_ptr<Echipa> echipaPolimorfica = std::make_unique<EchipaVolei>("Nationala Romania", 12, 50, 10, 1.85);
    echipaPolimorfica->afiseazaInformatii();

    // Conversie dinamică pentru a accesa metode din clasa derivată
    EchipaVolei* echipaDerivata = dynamic_cast<EchipaVolei*>(echipaPolimorfica.get());
    if (echipaDerivata) {
        std::cout << "Conversie reușită. Afișăm detalii suplimentare:\n";
        echipaDerivata->afiseazaNumeInaltime();
    } else {
        std::cout << "Eroare: Conversia dinamică a eșuat.\n";
    }

    std::cout << "\n==== Testare operatori și mutare cu std::unique_ptr ====\n";

    // Creăm o altă echipă și transferăm ownership-ul
    std::unique_ptr<Echipa> echipa3 = std::make_unique<Echipa>("Leii", 9, 18, 12);
    echipa3->afiseazaInformatii();

    // Mutăm echipa
    std::unique_ptr<Echipa> echipa4 = std::move(echipa3);
    if (!echipa3) {
        std::cout << "echipa3 nu mai deține ownership-ul resursei.\n";
    }
    echipa4->afiseazaInformatii();

    std::cout << "\n==== Distrugerea automată a resurselor ====\n";
    // Obiectele create cu smart pointers vor fi distruse automat la sfârșitul funcției.
    std::cout << "Resursele vor fi eliberate automat.\n";

    return 0;
}
