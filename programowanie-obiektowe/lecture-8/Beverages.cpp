#include "Beverages.h"
#include<iostream>

void HotBeverage::identify() const
{
	std::cout << "I am a hot beverage\n";
}

void HotMilkshake::identify() const
{
	std::cout << "I am a hot milkshake - added milk volume: " << milk_volume << "\n";
	return;
}

void Tea::identify() const
{
	std::cout << "I am a tea! I have been brewed for: " << brewing_time << "\n";
	return;
}

void MilkTea::identify() const
{
	std::cout << "I am a milk tea, but the below is also true!\n";
	Tea::identify();
	HotMilkshake::identify();
}
