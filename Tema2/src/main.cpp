#include <iostream>
#include "Echipa.hpp"
#include "EchipaVolei.hpp"

int main() {
    std::cout << "=== Cerinta 1: Suprascrierea copy constructor-ului ===\n";
    Echipa* team1 = new Echipa("Steaua", 11, 30, 10);
    std::cout << "Echipa originală creată dinamic:\n";
    team1->afiseazaInformatii();

    std::cout << "\nCreăm o copie a echipei originale folosind copy constructorul:\n";
    Echipa* team2 = new Echipa(*team1); // Apel explicit al copy constructorului
    std::cout << "Echipa copiată:\n";
    team2->afiseazaInformatii();

    std::cout << "\n=== Cerinta 2: Crearea unui move constructor ===\n";
    Echipa* team3 = new Echipa("Dinamo", 15, 20, 5);
    std::cout << "Echipa originală creată dinamic:\n";
    team3->afiseazaInformatii();

    std::cout << "\nMutăm echipa originală într-un nou obiect folosind move constructorul:\n";
    Echipa* team4 = new Echipa(std::move(*team3)); // Apel explicit al move constructorului
    std::cout << "Echipa mutată:\n";
    team4->afiseazaInformatii();

    std::cout << "\n=== Cerinta 3: Initializarea obiectelor înainte de utilizare ===\n";
    Echipa* team5 = new Echipa(); // Constructor implicit
    std::cout << "Echipa creată dinamic cu constructorul implicit:\n";
    team5->afiseazaInformatii();

    std::cout << "\nAdăugăm puncte echipei inițializate:\n";
    team5->adaugaPuncte(15);
    team5->afiseazaInformatii();

    std::cout << "\n=== Cerinta 4: Ce funcții sunt generate implicit de C++? ===\n";
    std::cout << "Funcțiile generate implicit de C++ includ:\n";
    std::cout << "1. Default constructor\n";
    std::cout << "2. Copy constructor\n";
    std::cout << "3. Move constructor\n";
    std::cout << "4. Operator= pentru copiere\n";
    std::cout << "5. Operator= pentru mutare\n";
    std::cout << "6. Destructor\n";

    std::cout << "\nTestăm ce funcții sunt generate și apelate:\n";
    Echipa* team6 = new Echipa("Rapid", 8, 15, 6);
    Echipa* team7 = new Echipa(*team6); // Copy constructor
    std::cout << "Echipa creată prin copiere:\n";
    team7->afiseazaInformatii();

    Echipa* team8 = new Echipa(std::move(*team6)); // Move constructor
    std::cout << "Echipa creată prin mutare:\n";
    team8->afiseazaInformatii();

    std::cout << "\n=== Cerinta 5: Dezactivarea funcțiilor generate de compilator ===\n";
    std::cout << "Testăm dezactivarea move constructorului pentru EchipaVolei:\n";

    EchipaVolei* volleyballTeam = new EchipaVolei("CSM București", 12, 25, 8, 1.9);
    std::cout << "Echipa inițială creată dinamic:\n";
    volleyballTeam->afiseazaInformatii();

    // Încercăm să mutăm echipa, ceea ce ar trebui să producă o eroare de compilare
    // EchipaVolei* volleyballTeam2 = new EchipaVolei(std::move(*volleyballTeam));

    std::cout << "Mutarea echipei de volei este dezactivată folosind = delete\n";

   std::cout << "\n=== Ierarhia ===\n\n";

    // Creăm un obiect de tip Echipa* care pointează la o instanță de EchipaVolei
    Echipa* echipaPolimorfica = new EchipaVolei("Nationala Romania", 12, 50, 10, 1.85);
    std::cout << "Afisare folosind pointerul de bază (Echipa*):\n";
    echipaPolimorfica->afiseazaInformatii();

    std::cout << "\nDinamic apelăm metode specifice clasei derivate:\n";
    // Folosim dynamic_cast pentru a accesa metode din clasa derivată
    EchipaVolei* echipaVolei = dynamic_cast<EchipaVolei*>(echipaPolimorfica);
    if (echipaVolei) {
        echipaVolei->afiseazaNumeInaltime();
    } else {
        std::cout << "Eroare: Conversia dinamică la EchipaVolei a eșuat.\n";
    }

    // Încearcă să apeleze metoda specifică unei clase derivate cu un pointer de bază
    std::cout << "\nTestăm comportamentul la polimorfism:\n";
    Echipa* echipaDeBaza = new Echipa("Generic Team", 10, 30, 5);
    echipaDeBaza->afiseazaInformatii();

    // Acum încercăm să tratăm echipaDeBaza ca fiind EchipaVolei
    EchipaVolei* conversieGresita = dynamic_cast<EchipaVolei*>(echipaDeBaza);
    if (conversieGresita) {
        conversieGresita->afiseazaNumeInaltime();
    } else {
        std::cout << "Conversia dinamică la EchipaVolei a eșuat (așa cum era de așteptat).\n";
    }

    // Testăm comportamentul în funcție de apeluri polimorfice
    std::cout << "\nApeluri prin polimorfism:\n";
    EchipaVolei* echipaDerivata = new EchipaVolei("Volley Pro", 14, 40, 7, 1.9);
    Echipa* pointerDeBaza = echipaDerivata; // Pointer de bază către un obiect derivat
    pointerDeBaza->afiseazaInformatii();   // Apel polimorfic la metoda suprascrisă

    // Eliberăm memoria alocată dinamic
    delete team1;
    delete team2;
    delete team3; // Este deja golită, dar trebuie eliberată
    delete team4;
    delete team5;
    delete team6; // Este deja golită, dar trebuie eliberată
    delete team7;
    delete team8;
    delete volleyballTeam;
    delete echipaPolimorfica; // Destructorul corect trebuie să fie apelat datorită virtualității
    delete echipaDeBaza;
    delete pointerDeBaza;

    return 0;
}
