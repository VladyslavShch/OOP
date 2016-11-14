#ifndef _STANDARTWATERCONSUMER_HPP_
#define _STANDARTWATERCONSUMER_HPP_

#include "waterconsumer.hpp"


class StandartWC
	: public WaterConsumer
{
	const int m_Minimal;

	int  m_NumberOfUsers;

	StandartWC ( const StandartWC & );
	 
	StandartWC ( StandartWC & );

public:

	void GetDebt( int _price ) override;

	StandartWC( int _UniqueID, std::string _Name, std::string _Address, int _number );

	void GetWater( int _water ) override;

	StandartWC * asStandartWC() override { return this; }

};






#endif //_STANDARTWATERCONSUMER_HPP_