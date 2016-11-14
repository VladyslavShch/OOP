#include "coffe_machine.hpp"
#include <cassert>

std::ostream & operator << ( std::ostream& _o, const CoffeMachine & _cm)
{
	_o << _cm.SeedsInfo() << ' ' << _cm.WaterInfo() << ' ' << _cm.PortionsInfo() << std::endl;
	return _o;
}

CoffeMachine::CoffeMachine ( int _max_coffe, int _max_water, int _max_portion )
{
	m_Machine[Max_seeds] = _max_coffe;
	m_Machine[Max_water] = _max_water;
	m_Machine[Max_portion] = _max_portion;
	m_Machine[Current_seeds] = 0;
	m_Machine[Current_rubbish] = 0;
	m_Machine[Current_water] = 0;
}

//CoffeMachine::~CoffeMachine()
//{
//	delete[] m_Machine;
//}

int CoffeMachine::FillSeeds()
{
	int temp = m_Machine[Max_seeds] - m_Machine[Current_seeds];
	m_Machine[Current_seeds] = m_Machine[Max_seeds];
	return temp;
}

int CoffeMachine::FillWater()
{
	int temp = m_Machine[Max_water] - m_Machine[Current_water];
	m_Machine[Current_water] = m_Machine[Max_water];
	return temp;
}

bool CoffeMachine::MakeCoffe( int _type, int _power )
{
	assert ( _type == Espresso || _type == Americano);
	assert ( _power >= Light && _power <= Strong );
	if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] == 0 || m_Machine[Current_water] == 0 )
		return false;
	else if ( _type == Espresso && _power == Light )
	{
		if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 4 || m_Machine[Current_water] < 120 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 4;
			m_Machine[Current_water] = m_Machine[Current_water] - 120;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 1;
			return true;
		}
	}
	else if ( _type == Espresso && _power == Middle )
	{
		if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 120 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 8;
			m_Machine[Current_water] = m_Machine[Current_water] - 120;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 1;
			return true;
		}
	}
	else if ( _type == Espresso && _power == Strong )
	{
		if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 12 || m_Machine[Current_water] < 120 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 12;
			m_Machine[Current_water] = m_Machine[Current_water] - 120;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 1;
			return true;
		}
	}
	else if ( _type == Americano && _power == Light )
	{
		if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 4 || m_Machine[Current_water] < 200 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 4;
			m_Machine[Current_water] = m_Machine[Current_water] - 200;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 1;
			return true;
		}
	}
	else if ( _type == Americano && _power == Middle )
	{
		if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 200 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 8;
			m_Machine[Current_water] = m_Machine[Current_water] - 200;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 1;
			return true;
		}
	}
	else if ( _type == Americano && _power == Strong )
	{
		if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 12 || m_Machine[Current_water] < 200 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 12;
			m_Machine[Current_water] = m_Machine[Current_water] - 200;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 1;
			return true;
		}
	}
}

bool CoffeMachine::MakeDoubleCoffe( int _type, int _power )
{
	assert ( _type == Espresso || _type == Americano);
	assert ( _power >= Light && _power <= Strong );
	if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] == 0 || m_Machine[Current_water] == 0 )
		return false;
	else if ( _type == Espresso && _power == Light )
	{
		if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion]-1 || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 240 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 8;
			m_Machine[Current_water] = m_Machine[Current_water] - 240;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 2;
			return true;
		}
	}
	else if ( _type == Espresso && _power == Middle )
	{
		if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion]-1 || m_Machine[Current_seeds] < 16 || m_Machine[Current_water] < 240 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 16;
			m_Machine[Current_water] = m_Machine[Current_water] - 240;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 2;
			return true;
		}
	}
	else if ( _type == Espresso && _power == Strong )
	{
		if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion]-1 || m_Machine[Current_seeds] < 24 || m_Machine[Current_water] < 240 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 24;
			m_Machine[Current_water] = m_Machine[Current_water] - 240;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 2;
			return true;
		}
	}
	else if ( _type == Americano && _power == Light )
	{
		if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion]-1 || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 400 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 8;
			m_Machine[Current_water] = m_Machine[Current_water] - 400;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 2;
			return true;
		}
	}
	else if ( _type == Americano && _power == Middle )
	{
		if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion]-1 || m_Machine[Current_seeds] < 16 || m_Machine[Current_water] < 400 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 12;
			m_Machine[Current_water] = m_Machine[Current_water] - 400;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 2;
			return true;
		}
	}
	else if ( _type == Americano && _power == Strong )
	{
		if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion]-1 || m_Machine[Current_seeds] < 24 || m_Machine[Current_water] < 400 ) return false;
		else
		{
			m_Machine[Current_seeds] = m_Machine[Current_seeds] - 24;
			m_Machine[Current_water] = m_Machine[Current_water] - 400;
			m_Machine[Current_rubbish] = m_Machine[Current_rubbish] + 2;
			return true;
		}
	}
}

void CoffeMachine::CleanMachine()
{
	if ( m_Machine[Current_water] >= 500 )
	{
		m_Machine[Current_rubbish] = 0;
		m_Machine[Current_water] = m_Machine[Current_water] - 500;
	}
	else 
	{
		m_Machine[Current_rubbish] = m_Machine[Current_rubbish] - m_Machine[Current_rubbish] * m_Machine[Current_water] / 500;
		m_Machine[Current_water] = 0;
	}
}

bool CoffeMachine::NumberOfPortion( int _type, int _power )
{
	if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] == 0 || m_Machine[Current_water] == 0 )
		return false;
	else
	switch( _type )
	{
	case Espresso:
		switch( _power )
		{
		case Light:
			if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 4 || m_Machine[Current_water] < 120 ) return false;
			else
				return true;
			break;
		case Middle:
			if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 120 ) return false;
			else
				return true;
			break;
		case Strong:
			if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 12 || m_Machine[Current_water] < 120 ) return false;
			else
				return true;
			break;
		}
		break;
	case Americano:
		switch( _power )
		{
		case Light:
			if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 4 || m_Machine[Current_water] < 200 ) return false;
			else
				return true;
			break;
		case Middle:
			if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 200 ) return false;
			else
				return true;
			break;
		case Strong:
			if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] < 12 || m_Machine[Current_water] < 200 ) return false;
			else
				return true;
			break;
		}
	}
}

bool CoffeMachine::NumberOfPortion( int _type, int _power, int _double )
{
	assert ( _double == Double );
	if ( m_Machine[Current_rubbish] == m_Machine[Max_portion] || m_Machine[Current_seeds] == 0 || m_Machine[Current_water] == 0 )
		return false;
	else
	switch( _type )
	{
	case Espresso:
		switch( _power )
		{
		case Light:
			if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion] - 1 || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 240 ) return false;
			else
				return true;
			break;
		case Middle:
			if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion] - 1 || m_Machine[Current_seeds] < 16 || m_Machine[Current_water] < 240 ) return false;
			else
				return true;
			break;
		case Strong:
			if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion] - 1 || m_Machine[Current_seeds] < 24 || m_Machine[Current_water] < 240 ) return false;
			else
				return true;
			break;
		}
		break;
	case Americano:
		switch( _power )
		{
		case Light:
			if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion] - 1 || m_Machine[Current_seeds] < 8 || m_Machine[Current_water] < 400 ) return false;
			else
				return true;
			break;
		case Middle:
			if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion] - 1 || m_Machine[Current_seeds] < 16 || m_Machine[Current_water] < 400 ) return false;
			else
				return true;
			break;
		case Strong:
			if ( m_Machine[Current_rubbish] >= m_Machine[Max_portion] - 1 || m_Machine[Current_seeds] < 24 || m_Machine[Current_water] < 400 ) return false;
			else
				return true;
			break;
		}
	}
}