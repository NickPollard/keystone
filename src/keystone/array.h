// Array.h
#pragma once

/*
  Fixed Array

  An array of Fixed size, containing objects rather than pointers-to-objects.
  i.e. object array[size];

  Objects are Fixed and are never moved once created (though can be destroyed)

  Use a linked list of empty pointers in unused spaces to define which points are valid and which are not

  Initializing is O(n)
  Adding an element is O(1)
  Removing an element is O(1)
   */

template <typename T>
  class FixedArray {
    public:
      // Add `object` to the array
      auto add( T object ) -> T* {
        vAssert( firstFree < end );

        T* nextFree = *firstFree;
        T* insertedAt = firstFree;
        *insertedAt = object;
        firstFree = nextFree;
        return insertedAt;
      }

      void remove( T* object ) {
        vAssert( object >= array && object < end );
        *(T**)object = firstFree;
        firstFree = object;
      }

      // TODO remove(T) - i.e. linear search for equality and then remove

      // Create a new array
      FixedArray( int _count ) :
        count( _count ) {
        array = mem_alloc( sizeof( T ) * count );
        end = &array[count];
        firstFree = &array[0]; // When created the array is empty, so the first element must be free
        // init all spare spaces, they all point to the next (and the last points past the end)
        for ( int i = 0; i < count; ++i )
          *static_cast<T**>(&array[i]) = &array[i + 1];
      }

    private:
      T*     array;
      size_t count;
      T*     firstFree;
      T*     end;
  };

// template <typename T>
//   class Slice {}
