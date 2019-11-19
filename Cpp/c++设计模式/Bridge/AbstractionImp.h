#pragma once

class AbstractionImp
{
public:
	virtual ~AbstractionImp();
	virtual void Operation() = 0;

protected:
	AbstractionImp();
private:

};

class ConcreteAbstractionImpA : public AbstractionImp
{
public:
	ConcreteAbstractionImpA();
	~ConcreteAbstractionImpA();

	// ͨ�� AbstractionImp �̳�
	virtual void Operation() override;
private:

};

class ConcreteAbstractionImpB : public AbstractionImp
{
public:
	ConcreteAbstractionImpB();
	~ConcreteAbstractionImpB();

	// ͨ�� AbstractionImp �̳�
	virtual void Operation() override;
private:

};


