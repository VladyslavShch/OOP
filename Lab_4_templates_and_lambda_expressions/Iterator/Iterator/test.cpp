#include "integer_queue_circular_array_impl.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include "Date.hpp"

template< typename It, typename T >
It MyFind ( It _first, It _last, const T & _value )
{
    It current = _first;
    while ( current != _last )
    {
        if ( * current == _value )
            return current;
        ++ current;
    }

    return _last;
}


int main()
{
	try
	{
		Queue < int > myQueue;
		myQueue.Push( 1 );
		myQueue.Push( 2 );
		myQueue.Push( 3 );
		myQueue.Push( 4 );
		myQueue.Push( 5 );
		myQueue.Push( 6 );



		assert ( ! myQueue.IsEmpty() && ! myQueue.IsFull() && myQueue.Front() == 1 );

		myQueue.Pop();

		assert ( myQueue.Front() == 2 );

		const Queue< int >::Iterator it = MyFind( myQueue.begin(), myQueue.end(), 3 );
		assert( * it == 3 );
		

		Queue < std::string > myQueue2( 6 );
		myQueue2.Push( "S" );
		myQueue2.Push( "t" );
		myQueue2.Push( "r" );
		myQueue2.Push( "i" );
		myQueue2.Push( "n" );
		myQueue2.Push( "g" );

		assert ( myQueue2.IsFull() );

		Date a[3];

		Queue < Date > myQueue3( 3 );
		myQueue3.Push( a[0] );
		myQueue3.Push( a[1] );
		myQueue3.Push( a[2] );

		assert ( myQueue3.IsFull() );

	}
	catch ( const char * _error )
	{
		std::cout << "Error: " << _error << std::endl;
	}
}