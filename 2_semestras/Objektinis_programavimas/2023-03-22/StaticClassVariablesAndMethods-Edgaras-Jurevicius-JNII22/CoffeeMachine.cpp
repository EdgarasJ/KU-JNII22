/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-22
*/

#include "CoffeeMachine.h"

Drink* CoffeeMachine::drinks[5] = { new Drink, new Drink("Latte", 2.50), new Drink("Cappuccino", 2.00), new Drink("Expresso", 1.00), new Drink("Mocha", 1.25) };
double CoffeeMachine::totalPrice = 0.0;
double CoffeeMachine::amountPaid = 0.0;
double CoffeeMachine::leftToPay = 0.0;
std::vector<Drink*> CoffeeMachine::selectedDrinks = {};

// constructor and destructor
CoffeeMachine::CoffeeMachine() {
    chooseDrinks();
}
CoffeeMachine::~CoffeeMachine() {
    for (int i = 4; i > -1; i--) {
        delete drinks[i];
    }
}
// output
void CoffeeMachine::printSelection() {
    std::cout << "Please, choose a drink:" << std::endl;
    for (int i = 4; i > -1; i--) {
        std::cout << std::setw(2) << i + 1 << ". ";
        drinks[i]->printDrink();
    }
    std::cout << " 0. Pay for drinks" << std::endl;
    std::cout << "Total Price: " << std::fixed << std::setprecision(2) << totalPrice << std::endl;
}
void CoffeeMachine::returnChange() {
    int amountLeft = (amountPaid - leftToPay) * 100;
    if (amountLeft < 0) {
        std::cout << "Not suficient amount paid to cover a bill." << std::endl;
        leftToPay = amountLeft / -100.00;
        pay();
        return;
    }
    int denominations[] = { 200, 100, 50, 20, 10, 5 };
    std::string denominationsStr[] = { "2 EUR", "1 EUR", "0.50 EUR", "0.20 EUR", "0.10 EUR", "0.05 EUR" };
    int amount = 0;
    std::string changeText = "";
    for (int i = 0; i < 6; i++) {
        amount = amountLeft / denominations[i];
        amountLeft %= denominations[i];
        if (amount > 0) {
            changeText.append(std::to_string(amount));
            changeText.append(" of ");
            changeText.append(denominationsStr[i]);
            changeText.append(" denomination coins\n");
        }
    }
    std::cout << "Your change: " << std::endl;
    std::cout << changeText;
}
// input
void CoffeeMachine::chooseDrinks() {  
    char choice;
    bool startPaying = false;
    while (!startPaying)
    {
        printSelection();
        std::cin >> choice;

        switch (choice)
        {
        case '0':
            startPaying = true;
            leftToPay = totalPrice;
            pay();
            break;
        case '1':
            selectedDrinks.push_back(drinks[0]);
            totalPrice += drinks[0]->getPrice();
            break;
        case '2':
            selectedDrinks.push_back(drinks[1]);
            totalPrice += drinks[1]->getPrice();
            break;
        case '3':
            selectedDrinks.push_back(drinks[2]);
            totalPrice += drinks[2]->getPrice();
            break;
        case '4':
            selectedDrinks.push_back(drinks[3]);
            totalPrice += drinks[3]->getPrice();
            break;
        case '5':
            selectedDrinks.push_back(drinks[4]);
            totalPrice += drinks[4]->getPrice();
            break;
        default:
            std::cout << "Error: Wrong input." << std::endl;
        }
    }
}
void CoffeeMachine::pay() {
    std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
    std::cout << "Your selected drinks:" << std::endl;
    for (int i = 0; i < selectedDrinks.size(); i++) {
        selectedDrinks[i]->printDrink();
    }
    std::cout << "Total Prce  : " << std::fixed << std::setprecision(2) << totalPrice << std::endl;
    std::cout << "Left to Pay : " << std::fixed << std::setprecision(2) << leftToPay << std::endl;
    std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
    std::cout << "Please, enter payment amount: " << std::endl;
    std::cin >> amountPaid;
    returnChange();
}