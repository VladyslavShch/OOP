#include <cassert>

template< typename T >
class Queue
{
private:

	int m_Size;
	T * m_pData;
	int m_FrontIndex;
	int m_BackIndex;
	
	

public:

	class Iterator
    {
        int m_pCurrentIndex;
		bool m_way;
		T m_indexValue;
		T * it_Data;
	public:
        Iterator ( bool way , bool begin, Queue *queue)
			: it_Data( queue->m_pData )
		{
			m_way = way;
			if( begin )
			{
				if( way )
				{
					m_pCurrentIndex = queue->m_FrontIndex;
					m_indexValue = *(queue->m_pData + queue->m_FrontIndex);
				}
				else
				{
					m_pCurrentIndex = queue->m_BackIndex;
					m_indexValue = *(queue->m_pData + queue->m_BackIndex);
				}
			}
			else
			{
				if( way )
					m_pCurrentIndex = queue->m_BackIndex;
				else
					m_pCurrentIndex = queue->m_FrontIndex;
				m_indexValue = *( it_Data + ( queue->m_BackIndex ) );
			}
        }

		bool operator == ( const Iterator & _it ) const
        {
			if( this->m_way != _it.m_way )
				throw ("incorrect iterator. #operator == Iterator. #way");
            return m_pCurrentIndex == _it.m_pCurrentIndex;
        }

        bool operator != ( const Iterator & _it ) const
        {
            return !( * this == _it );
        }

        Iterator & operator ++ ()
        {
			if( m_way )
			{
				++m_pCurrentIndex;
				m_indexValue = *(it_Data + m_pCurrentIndex);
			}
			else
			{
				--m_pCurrentIndex;
				m_indexValue = *(it_Data + m_pCurrentIndex);
			}
            return * this;
        }


        const T& operator * () const
        {
            return m_indexValue;
        }
		friend Iterator;
    };

	Queue();

	Queue( int _fixedSize );

	Queue ( const Queue & _queue );

	Queue ( Queue & _queue );

	~Queue();

	Queue & operator = ( const Queue & _queue );

	Queue & operator = ( Queue & _queue );

	void Clear();

	int Size() const;

	int Capacity() const;

	bool IsEmpty() const;

	bool IsFull() const;

	int NextIndex( int _index );

	void Push( T _value );

	void Pop();

	T Front () const;

	Iterator begin()
	{
		return Iterator( true, true,  this );
	}

	Iterator end()
	{
		return Iterator( true, false, this );
	}

	Iterator rbegin()
	{
		return Iterator( false, true,  this );
	}

	Iterator rend()
	{
		return Iterator( false, false, this );
	}

	friend Iterator;
};

template< typename T >
Queue< T >::Queue()
	: m_Size( 10 + 1 )
	, m_FrontIndex( 0 )
	, m_BackIndex( 0 )
{
	m_pData = new T[ m_Size ];
}

template< typename T >
Queue< T >:: Queue( const Queue & _queue )
	: m_Size( _queue.m_Size )
	, m_FrontIndex( _queue.m_FrontIndex )
	, m_BackIndex( _queue.m_BackIndex )
{
	m_pData = new T[ m_Size ] ;
    

    // Поочередно вставлем элементы
	int nActual = _queue.Size();
    for ( int i = 0; i < nActual; i++ )
        Push( _queue.m_pData[ i ] );

}

template< typename T >
Queue< T >:: Queue( Queue & _queue )
	: m_Size( _queue.m_Size )
	, m_pData( _queue.m_pData )
	, m_FrontIndex( _queue.m_FrontIndex )
	, m_BackIndex( _queue.m_BackIndex )
{
	_queue.m_pData = nullptr;
}

template< typename T >
Queue< T >& Queue< T >::operator = ( const Queue & _queue )
{
    // Защита от присвоения на самого себя
	if ( this == & _queue )
   	 return * this;

    // Освобождаем старый блок и выделяем новый
    delete[] m_pData;
    m_Size  = _queue.m_Size;
    m_pData = new T[ m_Size ];

    // Поочередно вставлем элементы
	int nActual = _queue.Size();
    for ( int i = 0; i < nActual; i++ )
        Push( _queue.m_pData[ i ] );

	m_BackIndex = _queue.m_BackIndex;

	m_FrontIndex = _queue.m_FrontIndex;

    // Возвращаем ссылку на себя
    return * this;
}

// Реализация оператора перемещающего присвоения
template< typename T >
Queue< T >& Queue< T >::operator = ( Queue & _queue )
{
    // Защита от присвоения на самого себя
    if ( this == & _s )
   	 return * this;

    // Освобождаем старый блок данных
    delete[] m_pData;

    // Присваиваем себе ресурсы “умирающего”
    m_Size  = _queue.m_Size;

    m_pData = _queue.m_pData;

    m_BackIndex = _queue.m_BackIndex;

	m_FrontIndex = _queue.m_FrontIndex;

	_queue.m_pData = nullptr;

    // Возвращаем ссылку на себя
    return * this;
}


template< typename T >
Queue< T >::Queue( int _fixedSize )
	: m_Size( _fixedSize + 1 )
	, m_FrontIndex( 0 )
	, m_BackIndex( 0 )
{
	m_pData = new T[ m_Size ];
}

template< typename T >
Queue< T >::~Queue()
{
    delete[] m_pData;
}

template< typename T >
void Queue< T >::Clear ()
{
    m_FrontIndex = 0;
    m_BackIndex  = 0;
}

template< typename T >
int Queue< T >::Size() const
{
    // |-|-|-|-|-|-|        |-|-|-|-|-|-|  
    //   F     B                B     F

    return ( m_FrontIndex <= m_BackIndex ) ? 
               m_BackIndex - m_FrontIndex : 
               m_BackIndex + m_Size - m_FrontIndex;

}

template< typename T >
int Queue< T >::Capacity() const
{
	return m_Size + 1;
}

template< typename T >
bool Queue< T >::IsEmpty() const
{
    return Size() == 0;
}

template< typename T >
bool Queue< T >::IsFull() const
{
    return Size() == ( m_Size - 1 );
}

template< typename T >
int Queue< T >::NextIndex ( int _index )
{
    int index  = _index + 1;
    if ( index == m_Size )
        index = 0;
    return index;
}

template< typename T >
void Queue< T >::Push( T _value )
{
    if ( IsFull() ) 
		throw ( "Queue is full!" );

    m_pData[ m_BackIndex ] = _value;
    m_BackIndex = NextIndex( m_BackIndex );
}

template< typename T >
void Queue< T >::Pop()
{
    if ( IsEmpty() )
		throw ( "Queue is empty!" );
    m_FrontIndex = Queue::NextIndex( m_FrontIndex );
}

template< typename T >
T Queue< T >::Front() const
{
    if ( IsEmpty() )
		throw ( "Queue is empty!" );
    return m_pData[ m_FrontIndex ];
}
