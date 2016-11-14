#include "waterconsumer.hpp"

WaterConsumer::WaterConsumer( int _UniqueID, std::string _Name, std::string _Address )
	: m_UniqueID( _UniqueID )
	, m_Name( _Name )
	, m_Address( _Address )
{
}

std::string & WaterConsumer::Getname()
{
	return m_Name;
}

int WaterConsumer::GetID()
{
	return m_UniqueID;
}