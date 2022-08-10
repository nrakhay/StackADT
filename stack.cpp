
#include "stack.h"

void stack::ensure_capacity( size_t c ){
  if (c <= current_capacity) return;
  
  size_t sz = 2;
  while (sz < c){
    sz = sz * 2;
  }
  double *new_data = new double[sz];
  std::copy(data, data+current_size, new_data);
  delete[] data;
  data = new_data;
  current_capacity = sz;
}
  

stack::stack(){
  data = new double[4];
  current_capacity = 4;
  current_size = 0;
}
  

stack::stack( const stack& s ){
  current_capacity = s.current_capacity;
  current_size = s.current_size;
  data = new double[s.current_capacity];
  std::copy(s.data, s.data + s.current_size, data);
}
  

const stack& stack::operator = ( const stack& s ){
  // use ensure_capacity and std::copy. 
  ensure_capacity(s.current_size);
  std::copy(s.data, s.data + s.current_size, data);
  current_size = s.current_size;
  return *this;
}

stack::~stack( ){
  delete[] data;
}

void stack::push( double d ){
  ensure_capacity(1 + current_size);
  data[current_size] = d;
  current_size++;
}
  
stack::stack( std::initializer_list< double > init ){
  data = new double[4];
  current_size = 0;
  current_capacity = 4;
  
  for (double eachVal: init){
    push(eachVal);
  }
} 

  
void stack::pop( ){
  if (current_size == 0){
    throw std::runtime_error("pop: nothing in stack");
  }

  current_size = current_size - 1;
}

void stack::clear( ){
  current_size=0;
} 

void stack::reset( size_t s ){
  current_size = s;
}

double stack::peek( ) const{
  if (current_size == 0){
    throw std::runtime_error("peek: nothing in stack");
  }

  return data[current_size-1];
  } 

size_t stack::size( ) const{
  return current_size;
}

bool stack::empty( ) const{
  if(current_size == 0) return true;

  return false;
}

void stack::print( std::ostream& out ) const{
  out<<"stack: ";
  for (size_t c=0; c<current_size; c++){
    out<<data[c];
    if (c < current_size-1){
      out<<", ";
    }
  }

  out<<"\n";
}
 


