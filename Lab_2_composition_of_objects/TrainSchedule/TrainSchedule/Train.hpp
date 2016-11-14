#ifndef _TRAIN_HPP_
#define _TRAIN_HPP_

class Route;

class Train
{
	const int m_iTrainID;

	Route* m_Route;

private: //Disallowed

	Train ( const Train & );

	Train & operator = ( const Train & );

public:

	Train( int _ID );

	int GetID() const;

	void AddRoute( Route * _route );

	//~Train();

};

inline int Train::GetID() const
{
	return m_iTrainID;
}
#endif //  _TRAIN_HPP_