#ifndef _COUNTINGWATERCONSUMER_HPP_
#define _COUNTINGWATERCONSUMER_HPP_

#include "waterconsumer.hpp"


class CountingWC
	: public WaterConsumer
{

	int m_Last;

	CountingWC( const CountingWC & );

	CountingWC( CountingWC & );

public:

	void GetWater( int _water ) override;

	void GetDebt( int _price ) override;

	CountingWC( int _UniqueID, std::string _Name, std::string _Address );

	CountingWC * asCountingWC() override { return this; }

};






#endif //_COUNTINGWATERCONSUMER_HPP_