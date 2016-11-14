#include "standartwaterconsumer.hpp"

StandartWC::StandartWC( int _UniqueID, std::string _Name, std::string _Address, int _number )
	: WaterConsumer( _UniqueID, _Name, _Address )
	, m_NumberOfUsers( _number )
	, m_Minimal( 9 )
{
}

void StandartWC::GetWater( int _water )
{
	std::cout << "I'm ignored." << std::endl;
}

void StandartWC::GetDebt( int _price )
{
	std::cout << "Debt of user " << Getname() << " = " << m_NumberOfUsers * m_Minimal * _price << std::endl; 
}