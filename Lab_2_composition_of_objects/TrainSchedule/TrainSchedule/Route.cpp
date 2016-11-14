#include "Route.hpp"
#include "TrainScheduleItem.hpp"
#include "station.hpp"

Route::Route( int _ID )
	:m_iNumID( _ID )
{
}

void Route::AddSchedule( TrainScheduleItem * _schedule )
{
	m_Schedule.push_back( _schedule );
}

int Route::TakeTime() const
{
	if ( m_Schedule[0]->m_iComeTime < m_Schedule[m_Schedule.size() - 1]->m_iGoTime )
		return m_Schedule[m_Schedule.size() - 1]->m_iGoTime - m_Schedule[0]->m_iComeTime;
	else 
		return m_Schedule[m_Schedule.size() - 1]->m_iGoTime + ( 24*60 - m_Schedule[0]->m_iComeTime );
}

Route::~Route()
{
	for ( int i = 0; i < m_Schedule.size(); i++ )
		delete m_Schedule[ i ];
}