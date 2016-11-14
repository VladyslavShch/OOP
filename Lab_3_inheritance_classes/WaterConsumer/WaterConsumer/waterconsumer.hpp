#ifndef _WATERCONSUMER_HPP_
#define _WATERCONSUMER_HPP_

#include<string>
#include<iostream>

class CountingWC;
class StandartWC;
class SubsidizedWC;

class WaterConsumer
{
	int m_UniqueID;

	std::string m_Name;

	std::string m_Address;

	int m_AddressNum;

	WaterConsumer( const WaterConsumer & );

	WaterConsumer( WaterConsumer & );

protected:

	virtual void GetWater( int _water ) = 0;

	virtual void GetDebt( int _price ) = 0;

	WaterConsumer( int _UniqueID, std::string _Name, std::string _Address );

public:

	std::string & Getname();

	int GetID();

	virtual CountingWC * asCountingWC() { return nullptr; }
	virtual SubsidizedWC * asSubsidizedWC() { return nullptr; }
	virtual StandartWC * asStandartWC() { return nullptr; }

};





#endif //_WATERCONSUMER_HPP_