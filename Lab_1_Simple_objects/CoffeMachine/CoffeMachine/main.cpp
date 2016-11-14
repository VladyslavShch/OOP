#include "coffe_machine.hpp"

int main()
{
	CoffeMachine cm( 1000, 1200, 100 );

	std::cout <<  cm;

	cm.FillSeeds ();

	cm.FillWater ();

	cm.CleanRubbish();

	if  ( cm.NumberOfPortion( Espresso, Middle ) )
		cm.MakeCoffe( Espresso, Middle );
	if ( cm.NumberOfPortion( Americano, Light, Double ) )
		cm.MakeDoubleCoffe( Americano, Light );

		cm.MakeDoubleCoffe(Espresso, Strong );

	//cm.CleanMachine();

	std::cout << cm;

}