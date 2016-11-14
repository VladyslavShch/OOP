#ifndef _SUBSIDIZEDWATERCONSUMER_HPP_
#define _SUBSIDIZEDWATERCONSUMER_HPP_

#include "waterconsumer.hpp"


class SubsidizedWC
	: public WaterConsumer
{

	SubsidizedWC ( const SubsidizedWC & );

	SubsidizedWC ( SubsidizedWC & );

public:

	void GetDebt( int _price ) override;

	SubsidizedWC( int _UniqueID, std::string _Name, std::string _Address );

	void GetWater( int _water ) override;

	SubsidizedWC * asSubsidizedWC() override { return this; }

};






#endif //_SUBSIDIZEDWATERCONSUMER_HPP_