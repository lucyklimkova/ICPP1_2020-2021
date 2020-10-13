#include <iostream>
#include <exception>
#include "CashDesk.h"


int CashDesk::counterId = 1000;

CashDesk::~CashDesk() {
	delete[] allReceipts;
}

CashDesk::CashDesk() {
	amountOfReceipts = 0;
	allReceipts = new Receipt[10];
}


Receipt& CashDesk::getReceipt(int idReceipt) {
	for (int i = 0; i < amountOfReceipts; i++) {
		if (allReceipts[i].GetIdReceipt() == idReceipt) {
			return allReceipts[i];
		}
	}
	return allReceipts[0];
}

Receipt& CashDesk::createReceipt(double amount, double vat) {
	if (amountOfReceipts == 10) {
		throw "This CashDesk is full, you cannot add another Receipt";
	}
	allReceipts[amountOfReceipts].SetIdReceipt(counterId++);
	allReceipts[amountOfReceipts].SetAmount(amount);
	allReceipts[amountOfReceipts].SetVat(vat);

	return allReceipts[amountOfReceipts++];
}

double CashDesk::getAmountOfMoney() const {
	double total = 0;
	for (int i = 0; i < amountOfReceipts; i++) {
		total += allReceipts[i].GetAmount();
	}

	return total;
}

double CashDesk::getAmountWithVat() const {
	double amountWithVat = 0;
	for (int i = 0; i < amountOfReceipts; i++) {
		amountWithVat += allReceipts[i].GetAmount() * (1 + allReceipts[i].GetVat());
	}

	return amountWithVat;
}