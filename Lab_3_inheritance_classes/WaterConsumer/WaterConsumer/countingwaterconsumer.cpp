#include "countingwaterconsumer.hpp"

CountingWC::CountingWC( int _UniqueID, std::string _Name, std::string _Address )
	: WaterConsumer( _UniqueID, _Name, _Address )
{
}

void CountingWC::GetWater( int _water )
{
	m_Last = _water;
}

void CountingWC::GetDebt( int _price )
{
	std::cout << "Debt of user " << Getname() << " = " << m_Last * _price << std::endl; 
}