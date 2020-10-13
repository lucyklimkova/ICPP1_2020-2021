#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Receipt.h"
#include "CashDesk.h"

int main(int argc, char** argv) {

	CashDesk* cashDesk = new CashDesk();
	Receipt currentReceipt;

	srand(time(NULL)); //seed for random generator
	std::cout << "Creating random Receipts and printing them: " << std::endl;
	for (int i = 0; i < 12; i++) {

		double amount = rand() % 5000 + 50;
		double vat = (rand() % 40 + 1) / 100.00;

		try {
			currentReceipt = cashDesk->createReceipt(amount, vat);
			std::cout << "Receipt with ID: " << currentReceipt.GetIdReceipt() << " was succesfully created. Amount of money: " << currentReceipt.GetAmount() 
				<< " with VAT: " << currentReceipt.GetVat() << std::endl;
		}
		catch (const char* error) {
			std::cout << "Error---" << error << std::endl;
		}
	}

	std::cout << "-----Summary-----" << std::endl;
	std::cout << "Amount of money in all receipts: " << cashDesk->getAmountOfMoney() << std::endl;
	std::cout << "Amount of money in all receipts including VAT: " << cashDesk->getAmountWithVat() << std::endl;
}