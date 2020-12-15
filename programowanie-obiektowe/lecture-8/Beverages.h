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
	HotMilkshake(int _milk) : HotBeverage(), milk_volume(_milk) {}
	~HotMilkshake() = default;
	void identify() const;
private:
	int milk_volume;
};

class Tea : virtual public HotBeverage {
public:
	Tea(int _time) : HotBeverage(), brewing_time(_time) {}
	~Tea() = default;
	void identify() const;
private: 
	int brewing_time;
};

class MilkTea : public HotMilkshake, public Tea {
public:
	MilkTea(int _milk, int _time) : HotBeverage(), HotMilkshake(_milk), Tea(_time) {} 
	// oddly enough, in Visual Studio, I didn't have to add HotBeverage() for main to work...
	~MilkTea() = default;
	void identify() const;
};
#endif // CLASSES
