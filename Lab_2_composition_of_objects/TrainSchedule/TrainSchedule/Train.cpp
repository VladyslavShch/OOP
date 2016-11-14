#include "Train.hpp"


Train::Train( int _ID )
	:m_iTrainID( _ID )
{
}

void Train::AddRoute( Route * _route )
{
	m_Route = _route;
}

//Train::~Train()
//{
//    // Освобождаем блок для хранения маршрута
//	delete[] m_Route;
//}
