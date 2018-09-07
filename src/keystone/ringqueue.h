#pragma once
#include "mem/allocator.h"

template<typename T>
  class RingQueue {
    public:
      auto count() -> size_t { return last - first + ( last < first ? capacity : 0 ); }

      auto pop() -> T* {
        vAssert( count() > 0 );
        T* item = items[first];
        first = ( first + 1 ) % capacity;
        return item;
      }

      void push( T* item ) {
        vAssert( count() < capacity );
        items[last] = item;
        last = ( last + 1 ) % capacity;
      }

      void operator << ( T* item ) {
        push( item );
      }

      RingQueue(size_t _capacity) :
        capacity( _capacity ),
        first( 0 ),
        last( 0 ) {
        items = (T**)mem_alloc( sizeof( T* ) * capacity );
      };

    private:
      size_t first;
      size_t last;
      size_t capacity;
      T** items;
};
