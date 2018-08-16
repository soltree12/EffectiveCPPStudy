#pragma once
#include <iostream>
class BorrowableItem {
public:
	void checkOut()
	{
		std::cout << "BorrowableItem::checkOut" << std::endl;
	}
};

class ElectronicGadget {
private:
	bool checkOut() const
	{
		std::cout << "ElectronicGadget::checkOut" << std::endl;
	}
};

class MP3Player : public BorrowableItem, public ElectronicGadget {
};