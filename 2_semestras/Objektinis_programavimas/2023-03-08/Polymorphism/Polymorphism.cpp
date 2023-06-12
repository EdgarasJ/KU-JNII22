/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1: 2023-03-08
*/

#include <iostream>
#include <iomanip>
#include "TiesineFunkcija.h"
#include "LaipsnineFunkcija.h"
#include "Sinusoide.h"
#include "Skritulys.h"
#include "Staciakampis.h"
#include "Trikampis.h"
#include "PrekesSuNuolaida.h"

int main()
{
    Funkcija* func[6];
    func[0] = new TiesineFunkcija;
    func[1] = new TiesineFunkcija(3.0, 2.0, 5.0);
    func[2] = new LaipsnineFunkcija;
    func[3] = new LaipsnineFunkcija(2.0, 10.0);
    func[4] = new Sinusoide;
    func[5] = new Sinusoide(1.0);
    for (int i = 0; i < 6; i++) {
        func[i]->getFx();
    }

    GeometrineFigura* fig[6];
    fig[0] = new Skritulys;
    fig[1] = new Skritulys(3.0);
    fig[2] = new Staciakampis;
    fig[3] = new Staciakampis(2.0, 5.0);
    fig[4] = new Trikampis;
    fig[5] = new Trikampis(2.0, 1.0);
    for (int i = 0; i < 6; i++) {
        fig[i]->printArea();
    }

    Prekes* products[10];
    std::cout << "Please, enter a number of products You want to input (min: 1, max: 10): " << std::endl;
    int howMuch;
    std::string name;
    double price, discount;
    unsigned int amount;
    char c;
    std::cin >> howMuch;
    if (howMuch < 1) howMuch = 1;
    if (howMuch > 10) howMuch = 10;
    for (int i = 0; i < howMuch; i++) {
        std::cout << "Information for product Nr. " << i + 1 << " :" << std::endl;
        std::cout << "Please, enter a product name: " << std::endl;
        std::cin >> name;
        std::cout << "Please, enter a product price (1 pcs): " << std::endl;
        std::cin >> price;
        std::cout << "Please, enter a product amount: " << std::endl;
        std::cin >> amount;
        std::cout << "Please, choose if You want to apply discount for this product (y/n): " << std::endl;
        std::cin >> c;
        if (c == 'y') {
            std::cout << "Please, enter a percentage for discount: " << std::endl;
            std::cin >> discount;
            products[i] = new PrekesSuNuolaida(name, price, amount, discount);
        }
        else {
            products[i] = new Prekes(name, price, amount);
        }     
    }

    std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
    std::cout << "Shopping Cart:" << std::endl;

    for (int i = 0; i < howMuch; i++) {
        products[i]->printInfo();
    }

    for (int i = 5; i > -1; i--) {
        delete fig[i];
    }

    for (int i = howMuch - 1; i > -1; i--) {
        delete products[i];
    }
}