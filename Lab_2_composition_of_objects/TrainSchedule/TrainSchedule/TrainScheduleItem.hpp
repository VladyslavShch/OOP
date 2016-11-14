#ifndef _TRAINSCHEDULELTEM_HPP_
#define _TRAINSCHEDULELTEM_HPP_


class Station;

class TrainScheduleItem
{

	Station & m_Station;

	const int m_iComeTime;

	const int m_iGoTime;

private: //Other

	TrainScheduleItem ( const TrainScheduleItem & );

	TrainScheduleItem & operator = ( const TrainScheduleItem );

	friend class Route;

public:

	TrainScheduleItem ( Station & _Station, int _AriveHour, int _AriveMinutes,  int _GoHour, int _GoMinutes );

	Station & GetStation();

	int GetComeTime() const;

	int GetGoTime() const;

};

inline Station & TrainScheduleItem::GetStation()
{
	return m_Station;
}

inline int TrainScheduleItem::GetComeTime() const
{
	return m_iComeTime;
}

inline int TrainScheduleItem::GetGoTime() const
{
	return m_iGoTime;
}
#endif //  _TRAINSCHEDULELTEM_HPP_