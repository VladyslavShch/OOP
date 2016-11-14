#ifndef _STATION_HPP_
#define _STATION_HPP_

#include <string>

class Station
{

	const std::string m_sName;

	const int m_iPerNum;

private: //Other important elements

	int m_iRouteNum;

	Station & operator = ( const Station & );

	Station ( const Station & );

	friend class Route;

public:

	bool m_bCheck;

	Station ( std::string _name, int _iPerNum );

	std::string GetName() const;

	int GetPerNum() const;

	int GetRouteNum() const;

	void ChangeRouteNum();

	bool IsNotChecked();

};

inline std::string 
Station::GetName() const
{
	return m_sName;
}

inline int 
Station::GetPerNum() const
{
	return m_iPerNum;
}

inline int 
Station::GetRouteNum() const
{
	return m_iRouteNum;
}

inline bool Station::IsNotChecked()
{
	return !m_bCheck;
}
#endif //  _STATION_HPP_