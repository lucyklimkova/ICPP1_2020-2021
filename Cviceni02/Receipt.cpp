#include <iostream>
#include "Receipt.h"


int Receipt::GetIdReceipt() const {
	return idReceipt;
}

void Receipt::SetIdReceipt(int idReceipt) {
	this->idReceipt = idReceipt;
}

double Receipt::GetVat() const {
	return vat;
}

void Receipt::SetVat(double vat) {
	this->vat = vat;
}

double Receipt::GetAmount() const {
	return amount;
}

void Receipt::SetAmount(double amount) {
	this->amount = amount;
}

