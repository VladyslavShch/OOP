#include "station.hpp"

Station::Station ( std::string _name, int _pernum )
	: m_sName( _name )
	, m_iPerNum( _pernum )
	, m_iRouteNum( 0 )
	, m_bCheck( false )
{
}

void Station::ChangeRouteNum()
{
	m_iRouteNum++;
}