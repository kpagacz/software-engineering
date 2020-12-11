#ifndef CLASSES
#define CLASSES

class HotBeverage {
public:
	HotBeverage() = default;
	virtual ~HotBeverage() = default;
	virtual void identify() const;
};

class HotMilkshake : virtual public HotBeverage {
public:
	HotMilkshake() : HotBeverage() {}
	~HotMilkshake() = default;
};

class Tea : virtual public HotBeverage {
public:
	Tea() : HotBeverage() {}
	~Tea() = default;
};

class MilkTea : public HotMilkshake, public Tea {
public:
	MilkTea() : HotBeverage(), HotMilkshake(), Tea() {} // oddly enough, in Visual Studio, I didn't have to add HotBeverage() for main to work...
	~MilkTea() = default;
};
#endif // CLASSES
