#ifndef CASH_DESK_H
#define CASH_DESK_H

#include "Receipt.h"

class CashDesk {

	int amountOfReceipts;
	Receipt* allReceipts;
	static int counterId;

public:
	CashDesk();
	~CashDesk();
	Receipt& getReceipt(int idReceipt);
	Receipt& createReceipt(double amount, double vat);
	double getAmountOfMoney() const;
	double getAmountWithVat() const;
};

#endif // !CASH_DESK_H
