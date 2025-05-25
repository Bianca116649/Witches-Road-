#ifndef EXCEPTII_H
#define EXCEPTII_H
#include<string>
#include<stdexcept>

class eroareJoc: public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class inputInvalid: public eroareJoc {
public:
    explicit inputInvalid(const std::string& mesaj):
    eroareJoc("Eroare INPUT: " + mesaj) {}

};

class EroareNivel : public eroareJoc {
public:
    explicit EroareNivel(const std::string& mesaj):
    eroareJoc("Lvl error: " +  mesaj){}
};

class EroareActiune : public eroareJoc {
public:
    explicit EroareActiune(const std::string& mesaj)
        : eroareJoc("Actiune nereușită: " + mesaj) {}
};

class EroareInitializare : public eroareJoc {
public:
    explicit EroareInitializare(const std::string& mesaj)
        : eroareJoc("Initializare eșuată: " + mesaj) {}
};

class eroareObstacol : public eroareJoc {
public:
    explicit eroareObstacol(const std::string& mesaj):
    eroareJoc("Obstacol negasit: " + mesaj){}
};

#endif //EXCEPTII_H