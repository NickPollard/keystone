// list.h
#pragma once

struct list {
  void* head;
  void* tail;
};

/*
template <typename T>
  class List {
    public:
      List<T>* cons( T* h, List<T>* t );
      void del();
      int length();
    private:
      T* head;
      struct List<T>* tail;
  };
*/
