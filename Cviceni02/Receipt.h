#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt {

private:
	int idReceipt;
	double amount;
	double vat;

public:
	int GetIdReceipt() const;
	void SetIdReceipt(int idReceipt);
	double GetAmount() const;
	void SetAmount(double amount);
	double GetVat() const;
	void SetVat(double vat);
};

#endif // !RECEIPT_H