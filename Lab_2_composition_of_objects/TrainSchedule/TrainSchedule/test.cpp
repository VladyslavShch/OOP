#include "Route.hpp"
#include "station.hpp"
#include "Train.hpp"
#include "TrainScheduleItem.hpp"
#include <iostream>
#include <algorithm> 

void main()
{
	std::vector< Train* > pTrain;
	std::vector< Route* > pRoute;
	std::vector< Station* > pStation;


	for ( int i = 0; i < 5; i++ )
		pTrain.push_back( new Train( i ) );
	
	pStation.push_back( new Station( "Moskwa", 20 ) );
	pStation.push_back( new Station( "Donetsk", 10 ) );
	pStation.push_back( new Station( "Kharkiv", 10 ) );
	pStation.push_back( new Station( "Konstantinovka", 4 ) );
	pStation.push_back( new Station( "Kramatosk", 4 ) );
	pStation.push_back( new Station( "Slavyansk", 2 ) );
	pStation.push_back( new Station( "Lozova", 3 ) );
	pStation.push_back( new Station( "Izyum", 5 ) );
	pStation.push_back( new Station( "Krasnyy_Liman", 9 ) );
	pStation.push_back( new Station( "Balaklyeya", 2 ) );
	pStation.push_back( new Station( "Kyiv", 20 ) );

	for ( int i = 0; i < 5; i++ )
		pRoute.push_back( new Route( i + 100 ) );

	pRoute[0]->AddSchedule( new TrainScheduleItem( * pStation[ 2 ], 5, 55, 6, 18 ) );
	pRoute[0]->AddSchedule( new TrainScheduleItem( * pStation[ 6 ], 7, 50, 7, 55 ) );
	pRoute[0]->AddSchedule( new TrainScheduleItem( * pStation[ 5 ], 8, 58, 9, 00 ) );
	pRoute[0]->AddSchedule( new TrainScheduleItem( * pStation[ 4 ], 9, 10, 9, 15 ) );
	pRoute[0]->AddSchedule( new TrainScheduleItem( * pStation[ 3 ], 9, 35, 9, 40 ) );
	pRoute[0]->AddSchedule( new TrainScheduleItem( * pStation[ 1 ], 10, 00, 11, 00 ) );

	pTrain[0]->AddRoute( pRoute[0] );

	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 1 ], 5, 55, 6, 18 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 3 ], 6, 25, 6, 55 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 4 ], 7, 45, 7, 50 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 5 ], 8, 58, 9, 00 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 8 ], 9, 20, 9, 25 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 7 ], 11, 01, 11, 31 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 9 ], 13, 55, 13, 54 ) );
	pRoute[1]->AddSchedule( new TrainScheduleItem( * pStation[ 2 ], 15, 35, 15, 57 ) );

	pTrain[1]->AddRoute( pRoute[1] );

	pRoute[2]->AddSchedule( new TrainScheduleItem( * pStation[ 5 ], 8, 58, 9, 10 ) );
	pRoute[2]->AddSchedule( new TrainScheduleItem( * pStation[ 4 ], 9, 23, 9, 30 ) );
	pRoute[2]->AddSchedule( new TrainScheduleItem( * pStation[ 3 ], 9, 45, 9, 50 ) );
	pRoute[2]->AddSchedule( new TrainScheduleItem( * pStation[ 1 ], 10, 00, 10, 05 ) );

	pTrain[2]->AddRoute( pRoute[2] );

	pRoute[3]->AddSchedule( new TrainScheduleItem( * pStation[ 7 ], 4, 50, 5, 20 ) );
	pRoute[3]->AddSchedule( new TrainScheduleItem( * pStation[ 9 ], 6, 50, 7, 00 ) );
	pRoute[3]->AddSchedule( new TrainScheduleItem( * pStation[ 2 ], 8, 45, 9, 00 ) );

	pTrain[3]->AddRoute( pRoute[3] );

	pRoute[4]->AddSchedule( new TrainScheduleItem( * pStation[ 1 ], 21, 00, 21, 33 ) );
	pRoute[4]->AddSchedule( new TrainScheduleItem( * pStation[ 10 ], 1, 45, 2, 00 ) );

	pTrain[4]->AddRoute( pRoute[4] );

	int MaxTime = 0;
	int LastMaxTime = 0;
	int LastID = 0;
	int Temp;
	for ( int i = 0; i < 5; i++ )
	{
		MaxTime = 0;
		for ( int j = 0; j < pRoute.size(); j++ )
		{
			if ( i > 0 )
			{
				
				if ( pRoute[j]->TakeTime() >= MaxTime && LastMaxTime > pRoute[j]->TakeTime() && LastID != pRoute[j]->GetID() ) 
					{
						MaxTime = pRoute[j]->TakeTime();
						Temp = j;
					}
			}
			else
				if ( pRoute[j]->TakeTime() > MaxTime ) 
					{
						MaxTime = pRoute[j]->TakeTime();
						Temp = j;				
					}
				
		}
		LastMaxTime = MaxTime;
		LastID = pRoute[Temp]->GetID();
		
		std::cout << pRoute[Temp]->GetID() << " " << pRoute[Temp]->GetSchedule( 0 ).GetStation().GetName() << "-" << pRoute[Temp]->GetSchedule( pRoute[Temp]->ScheduleIndex() ).GetStation().GetName() << " " << pRoute[Temp]->TakeTime()/60 << ":" << pRoute[Temp]->TakeTime()%60/10 << pRoute[Temp]->TakeTime()%60%10 << std::endl;

	}

	std::cout << std::endl;

	std::string LastName = "0";
	for ( int i = 0; i < 5; i++ )
	{
		MaxTime = 0;
		for ( int j = 0; j < pStation.size(); j++ )
			if ( i > 0 )
			{
				if ( pStation[j]->GetRouteNum() >= MaxTime && LastMaxTime > pStation[j]->GetRouteNum() && LastName != pStation[j]->GetName() ) 
					{
						MaxTime = pStation[j]->GetRouteNum();
						Temp = j;
					}
			}
			else
				if ( pStation[j]->GetRouteNum() > MaxTime ) 
					{
						MaxTime = pStation[j]->GetRouteNum();
						Temp = j;
					}

				LastName = pStation[Temp]->GetName();
				LastMaxTime = MaxTime;

				std::cout << pStation[Temp]->GetName() << " " << pStation[Temp]->GetRouteNum() << std::endl;

	}

	std::cout << std::endl;

	int Schedule = 0;
	for ( int i = 0; i < pRoute.size(); i++  )
	{
	
		Schedule = 0;

		while ( pRoute[i]->GetSchedulePointer().size() != Schedule )
		{
			
			for ( int j = 0; j < pRoute.size(); j++  )
			{

				
				for ( int k = 0; k < pRoute[j]->GetSchedulePointer().size(); k++ )

					if ( pRoute[i]->GetSchedule( Schedule ).GetStation().GetName() == pRoute[j]->GetSchedule( k ).GetStation().GetName() 
						&& ( pRoute[i]->GetSchedule( Schedule ).GetComeTime() >= pRoute[j]->GetSchedule( k ).GetComeTime() 
						&& pRoute[i]->GetSchedule( Schedule ).GetGoTime() <= pRoute[j]->GetSchedule( k ).GetGoTime() ) 
						&& pRoute[i]->GetSchedule( Schedule).GetStation().IsNotChecked() )
						Temp++;

			}

			if ( pRoute[i]->GetSchedule( Schedule ).GetStation().GetPerNum() < Temp )
				std::cout << pRoute[i]->GetSchedule( Schedule ).GetStation().GetName() << std::endl;

			pRoute[i]->GetSchedule( Schedule ).GetStation().m_bCheck = true;

			Schedule += 1;

			Temp = 0;

		}

	}
	////////////////////////////////
	Temp = 0;
	bool _first = false, _second = false;
	for ( int i = 0; i < pStation.size() - 1; i++ )
		for ( int j = i + 1; j < pStation.size(); j++ )
		{
			for ( int k = 0; k < pRoute.size(); k++ )
			{
				for ( int l = 0; l < pRoute[k]->GetSchedulePointer().size(); l++ )
				{
					if ( pRoute[k]->GetSchedule(l).GetStation().GetName() == pStation[i]->GetName() )
						_first = true;
					if ( pRoute[k]->GetSchedule(l).GetStation().GetName() == pStation[j]->GetName() )
						_second = true;
				}
				if ( _first == true && _second == true )
					Temp++;
				_first = false;
				_second = false;
			}
			if ( Temp >= 3 )
				std::cout << pStation[ i ]->GetName() << "-" << pStation[ j ]->GetName() << std::endl;
			Temp = 0;
		}

		std::cout << std::endl;

		for ( int i = 0; i < pStation.size() - 1; i++ )
		for ( int j = i + 1; j < pStation.size(); j++ )
		{
			for ( int k = 0; k < pRoute.size(); k++ )
			{
				for ( int l = 0; l < pRoute[k]->GetSchedulePointer().size(); l++ )
				{
					if ( pRoute[k]->GetSchedule(l).GetStation().GetName() == pStation[i]->GetName() )
						_first = true;
					if ( pRoute[k]->GetSchedule(l).GetStation().GetName() == pStation[j]->GetName() )
						_second = true;
				}
				if ( _first == true && _second == true )
					Temp++;
				_first = false;
				_second = false;
			}
			if ( Temp == 0 )
				std::cout << pStation[ i ]->GetName() << "-" << pStation[ j ]->GetName() << std::endl;
			Temp = 0;
		}

		std::cout << std::endl;
	////////////////////////////////////////////

	for ( int i = 0; i < pTrain.size(); i++ )
		delete pTrain[ i ];

	for ( int i = 0; i < pRoute.size(); i++ )
		delete pRoute[ i ];

	for ( int i = 0; i < pStation.size(); i++ )
		delete pStation[ i ];

	//delete[] &pIntersect;
}