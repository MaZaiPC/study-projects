#pragma once

class Pair
{
public:
	Pair() {}
	~Pair() {}

	virtual Pair add(const Pair &c); // ��������
    virtual Pair mul(const Pair &c); // ���������
    virtual Pair sub(const Pair &c); // ���������
    virtual Pair div(const Pair &c); // �������
};

