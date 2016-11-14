#include "TrainScheduleItem.hpp"
#include "station.hpp"

int ConvertTime ( int _hour, int _minutes)
{
	return _hour * 60 + _minutes;
}

TrainScheduleItem::TrainScheduleItem ( Station & _Station, int _AriveHour, int _AriveMinutes,  int _GoHour, int _GoMinutes )
	:m_Station( _Station ),
	m_iComeTime( ConvertTime( _AriveHour, _AriveMinutes ) ),
	m_iGoTime( ConvertTime( _GoHour, _GoMinutes ) )
{
	_Station.ChangeRouteNum();
}