#include <iostream>
#include <list>

using namespace std;

class Person {
public:
    Person() {}

    Person(string vorname, string nachname, string adresse, string mail) {
        vorname_ = vorname;
        nachname_ = nachname;
        adresse_ = adresse;
        mail_ = mail;
        anzahlKunden_++;
        //test comment
    }

    Person(string mail) {
        vorname_ = "gast";
        nachname_ = "gast";
        adresse_ = "gast";
        mail_ = mail;
        anzahlKunden_++;
    }

    static int getAnzahlKunden();

    string getVorname() {
        return vorname_;
    }

    void setAnzahlProduke(int anzahlProdukte) {
        anzahlProdukte_ = anzahlProdukte;
    }

    int getAnzahlProdukte() {
        return anzahlProdukte_;
    }

private:
    string vorname_;
    string nachname_;
    string adresse_;
    string mail_;
    int anzahlProdukte_;
    static int anzahlKunden_;
};

int Person::anzahlKunden_ = 0;

int Person::getAnzahlKunden() {
    return anzahlKunden_;
}

void begruessung();

Person registrierungNeukunde();
// Das ist ein Funktionsprototyp
Person registrierungGast();

void bestaetigungRegistrierung(Person kunde);

void listeAnzeigen(list<Person> person);

enum Registrierung {
    kunde = 1, gast = 2
};

int main() {


    // inizialisierung von den Variabel
    int inStockComputer = 50;
    int registrierungsArt;
    Registrierung registrierung;
    list<Person> personenListe;


    while (true) {
        begruessung(); // in dieser schleife werden alle noten abgefragt und zusammengez�hlt
        cout << "Momentan haben wir" << Person::getAnzahlKunden() << " Kunden." << endl;

        cout << "Wenn Sie sich als Kunde registrieren moechten, druecken Sie bitte die 1." << endl;
        cout << "Falls Sie als Gast weiterfahren moechten waehlen Sie bitte die 2." << endl;
        cin >> registrierungsArt;

        registrierung = static_cast<Registrierung>(registrierungsArt);

        Person person;
        switch (registrierung) {
        case kunde:
            person = registrierungNeukunde();
            personenListe.push_back(person);
            break;
        case gast:
            person = registrierungGast();
            personenListe.push_back(person);
            break;
        default:
            cout << "Dies war keine gueltige Eingabe, bitte beginnen Sie erneut!";
            return 0;
        }
        /*
        if (person) {
            person = registrierungNeukunde();
            personenListe.push_back(person);
        } else if (registrierungsArt == 2) {
            person = registrierungGast();
            personenListe.push_back(person);
        } else {
            cout << "Dies war keine gueltige Eingabe, bitte beginnen Sie erneut!";
            return 0;
        }*/


        bestaetigungRegistrierung(person);

        int anzahlProdukte;
        cout << "Wie viele Computer moechten Sie kaufen? " << endl;
        cin >> anzahlProdukte;
        person.setAnzahlProduke(anzahlProdukte);

        if (person.getAnzahlProdukte() < inStockComputer) {
            cout << "Vielen Dank fuer ihre Bestellung" << endl;
        }
        else {
            cout << "Leider haben wir nicht genuegend Ger�t im Lager" << endl;
        }
        listeAnzeigen(personenListe);

    }

    return 0;
}

void begruessung() {
    cout << "###################################################" << endl;
    cout << "#_______________Online-Shop_______________________#" << endl;
    cout << "###################################################" << endl;
    cout << "Wilkommen in unserem Online-Shop" << endl;
}

Person registrierungNeukunde() {
    string vorname;
    string nachname;
    string adresse;
    string mail;

    cout << "Bitte geben Sie Ihren Vornamen ein:" << endl;
    cin >> vorname;
    cout << "Bitte geben Sie Ihren Nachnamen ein:" << endl;
    cin >> nachname;
    cout << "Bitte geben Sie Ihre Adresse ein:" << endl;
    cin >> adresse;
    cout << "Bitte geben Sie Ihre E-Mail-Adresse ein:" << endl;
    cin >> mail;

    Person kunde = Person(vorname, nachname, adresse, mail);

    return kunde;
}

Person registrierungGast() {
    string mail;

    cout << "Bitte geben Sie Ihre E-Mail-Adresse ein:" << endl;
    cin >> mail;

    Person kunde = Person(mail);

    return kunde;
}

void bestaetigungRegistrierung(Person kunde) {
    cout << "Vielen Dank fuer die Registrierung " << kunde.getVorname() << endl;
}

void listeAnzeigen(list<Person> person) {
    list<Person>::iterator it;
    for (it = person.begin(); it != person.end(); ++it) {
        cout << it->getVorname();
    }
    cout << '\n';
}
