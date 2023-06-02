
#include <iostream>
#include <string>

class IDiscount
{
public:
	virtual float discount(float price) = 0;
};

class client
{
private:
	int ID;
	std::string FullName;
	std::string EMail;
	IDiscount* Type;
public:
	client(int _ID, std::string _FullName, std::string _EMail, IDiscount* _Type)
	{
		ID = _ID;
		FullName = _FullName;
		EMail = _EMail;
		Type = _Type;
	}
	IDiscount* getType()
	{
		return Type;
	}
};

class AvarageDiscount : public IDiscount
{
public:
	float discount(float price) override
	{
		return 0;
	}
};
class ConstantDiscount : public IDiscount
{
public:
	float discount(float price) override
	{
		return price * 0.05;
	}
};
class VIPDiscount : public IDiscount
{
public:
	float discount(float price) override
	{
		return price * 0.2;
	}
};

void DiscountMathematic(int price, client* human)
{
	IDiscount* discount = human->getType();
	std::cout << discount->discount(price) << '\n';
}

int main()
{
	client human(123, "Oleg Olegovich Olegovor", "NoEmail@no.com", new VIPDiscount);
	int price = 100;
	DiscountMathematic(price, &human);
}