#include "countingwaterconsumer.hpp"
#include "standartwaterconsumer.hpp"
#include "subsidizedwaterconsumer.hpp"
#include "waterconsumer.hpp"

#include <iostream>
#include <fstream>
#include <vector>


enum status { COUNTED_PAYER, STANDARD_PAYER, SUBSIDIZED_PAYER, USE_WATER, SHOW_DEBT } _Status;

void GetDebtInf( std::vector< WaterConsumer* > _Consumers, int _id, int _price );
void GetWaterInf( std::vector< WaterConsumer* > _Consumers, int _id, int _water );
std::string getInBr(std::string& tmp)
		{
			int posf, poss;
			posf = tmp.find("\"") + 1;
			poss = tmp.find("\"", posf);
			return tmp.substr(posf, poss - posf);
		}

void ReadFromFile( std::vector< WaterConsumer* >& _Consumers, std::ifstream &_file )
{
	std::string Name, address, temp;
		int id, users;

		for ( int i = 0; i < 3; i++ )
		{
			if ( _file.eof() ) break;
			_file >> temp;
			if ( temp.find("COUNTED_PAYER") != std::string::npos )
			{
				_Status = COUNTED_PAYER;
				_file >> temp;
			}
			else 
				if ( temp.find("STANDARD_PAYER") != std::string::npos )
				{
					_Status = STANDARD_PAYER;
					_file >> temp;
				}
				else 
					if ( temp.find("SUBSIDIZED_PAYER") != std::string::npos )
					{
						_Status = SUBSIDIZED_PAYER;
						_file >> temp;
					}
			id = atoi( getInBr(temp).c_str() );
			_file >> temp;
			Name = getInBr ( temp );
			_file >> temp;
			address = getInBr ( temp );
			if ( _Status == 1 ) 
			{
				_file >> temp;
				users = atoi( getInBr(temp).c_str() );
			}
			if ( _Status == 0 ) 
			{
					_Consumers.push_back( new CountingWC( id, Name, address ) );
			}
			else if ( _Status == 1 )
			{
					_Consumers.push_back( new StandartWC( id, Name, address, users ) );
			}
			else if ( _Status == 2 ) 
				{
					_Consumers.push_back( new SubsidizedWC( id, Name, address ) );
				}

		}
}

void GetStatus ( std::vector< WaterConsumer* >& _Consumers, std::ifstream &_file )
{
	std::string temp;
	int id, water, price;

		while( _file )
		{
			if ( _file.eof() ) break;
			_file >> temp;
			if ( temp.find("USE_WATER") != std::string::npos )
			_Status = USE_WATER;
			else 
				if ( temp.find("SHOW_DEBT") != std::string::npos )
				_Status = SHOW_DEBT;
			_file >> temp;
			if ( _Status == 3 )
			{
				id = atoi( getInBr(temp).c_str() );
				_file >> temp;
				water = atoi( getInBr(temp).c_str() );
				GetWaterInf( _Consumers, id, water );
			}
				else if ( _Status == 4 )
				{
					id = atoi( getInBr(temp).c_str() );
					_file >> temp;
					price = atoi( getInBr(temp).c_str() );
					GetDebtInf( _Consumers, id, price );
				}
		}
}


int main()
{
	try 
	{
		std::vector< WaterConsumer* > Consumers;
		
		std::string Name, address, temp;
		int id, water, price, users;

		std::ifstream file ( "water_consumers.txt", std::ios_base::in );

		

		ReadFromFile( Consumers, file );
		GetStatus( Consumers, file ); 

	}
	catch( const char * _error )
	{
		std::cout << _error << std::endl;
	}
}

void GetWaterInf( std::vector< WaterConsumer* > _Consumers, int _id, int _water )
{
	bool count = false;
	for ( int i = 0; i < _Consumers.size(); i++)
		{
			if ( _Consumers[i]->asCountingWC() && _Consumers[i]->asCountingWC()->GetID() == _id )
			{
				_Consumers[i]->asCountingWC()->GetWater( _water );
				count = true;
				break;
			}
			else 
				if ( _Consumers[i]->asStandartWC() && _Consumers[i]->asStandartWC()->GetID() == _id )
				{
					_Consumers[i]->asStandartWC()->GetWater( _water );
					count = true;
					break;
				}
				else 
					if ( _Consumers[i]->asSubsidizedWC() && _Consumers[i]->asSubsidizedWC()->GetID() == _id )
					{
						_Consumers[i]->asSubsidizedWC()->GetWater( _water );
						count = true;
						break;
					}
		}
		
	if ( count == false )
		throw "There are no ID in USE_WATER";
}

void GetDebtInf( std::vector< WaterConsumer* > _Consumers, int _id, int _price )
{
	bool count = false;
	for ( int i = 0; i < _Consumers.size(); i++)
		{
			if ( _Consumers[i]->asCountingWC() && _Consumers[i]->asCountingWC()->GetID() == _id )
			{
				_Consumers[i]->asCountingWC()->GetDebt( _price );
				count = true;
				break;
			}
			else 
				if ( _Consumers[i]->asStandartWC() && _Consumers[i]->asStandartWC()->GetID() == _id )
				{
					_Consumers[i]->asStandartWC()->GetDebt( _price );
					count = true;
					break;
				}
				else 
					if ( _Consumers[i]->asSubsidizedWC() && _Consumers[i]->asSubsidizedWC()->GetID() == _id )
					{
						_Consumers[i]->asSubsidizedWC()->GetDebt( _price );
						count = true;
						break;
					}
		}
		
	if ( count == false )
		throw "There are no ID in SHOW_DEBT";
}