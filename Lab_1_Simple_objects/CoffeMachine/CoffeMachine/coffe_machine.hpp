//include guard
#ifndef _COFFE_MACHINE_HPP_
#define _COFFE_MACHINE_HPP_

#include <iostream>

//Types of coffe, which we can make
enum
{
	Espresso,
	Americano,
	Light,
	Middle,
	Strong,
	Double
};


class CoffeMachine
{
	enum
	{
		Max_seeds,
		Max_water,
		Max_portion,
		Current_seeds,
		Current_water,
		Current_rubbish,
	};

	//array, that keep info about Coffe Machine and its state
	int m_Machine[6];

public:	

    //Constructor
	CoffeMachine ( int _max_coffe, int _max_water, int _max_portion );

	int SeedsInfo () const;

	int WaterInfo () const;

	int PortionsInfo () const;

	int FillSeeds ();

	int FillWater ();

	void CleanRubbish();

	bool MakeCoffe( int _type, int _power );

	bool MakeDoubleCoffe( int _type, int _power );

	void CleanMachine();

	bool NumberOfPortion( int _type, int _power );

	bool NumberOfPortion( int _type, int _power, int _double );

};

inline int CoffeMachine::SeedsInfo () const
{
	return m_Machine[Current_seeds];
}

inline int CoffeMachine::WaterInfo() const
{
	return m_Machine[Current_water];
}

inline int CoffeMachine::PortionsInfo() const
{
	return m_Machine[Max_portion] - m_Machine[Current_rubbish];
}

inline void CoffeMachine::CleanRubbish ()
{
	m_Machine[Current_rubbish] = 0;
}

std::ostream & operator << ( std::ostream& _o, const CoffeMachine & _cm);

#endif // _COFFE_MACHINE_HPP_