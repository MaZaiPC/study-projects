#pragma once

class Pair
{
public:
	Pair() {}
	~Pair() {}

	virtual Pair add(const Pair &c); // Сложение
    virtual Pair mul(const Pair &c); // Умножение
    virtual Pair sub(const Pair &c); // Вычитание
    virtual Pair div(const Pair &c); // Деление
};

