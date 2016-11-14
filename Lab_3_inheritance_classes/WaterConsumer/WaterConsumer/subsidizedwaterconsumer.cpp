#include "subsidizedwaterconsumer.hpp"

SubsidizedWC::SubsidizedWC( int _UniqueID, std::string _Name, std::string _Address )
	: WaterConsumer( _UniqueID, _Name, _Address )
{
}

void SubsidizedWC::GetDebt( int _price )
{ 
	std::cout << Getname() << ": I am subsidized." << std::endl; 
}

void SubsidizedWC::GetWater( int _water )
{ 
	std::cout << "Water is unlimited." << std::endl; 
}