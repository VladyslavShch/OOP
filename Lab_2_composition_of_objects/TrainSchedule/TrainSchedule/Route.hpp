#ifndef _ROUTE_HPP_
#define _ROUTE_HPP_

#include <vector>

class TrainScheduleItem;

class Route
{
	const int m_iNumID;

	std::vector<TrainScheduleItem *> m_Schedule;

private: // Disallowed

	Route ( const Route & );

	Route & operator = ( const Route & );

public:

	Route( int _ID );

	int ScheduleIndex();

	int GetID() const;

	void AddSchedule( TrainScheduleItem * _schedele );

	int TakeTime() const;

	TrainScheduleItem & GetSchedule( int _index );

	std::vector< TrainScheduleItem* > & GetSchedulePointer();

	~Route();

};

inline int Route::GetID() const
{
	return m_iNumID;
}

inline TrainScheduleItem & Route::GetSchedule( int _index )
{
	return * m_Schedule[ _index ];
}

inline int Route::ScheduleIndex()
{
	return m_Schedule.size() - 1;
}

inline std::vector< TrainScheduleItem* > & Route::GetSchedulePointer()
{
	return m_Schedule;
}
#endif //  _ROUTE_HPP_