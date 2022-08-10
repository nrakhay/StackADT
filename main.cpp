
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

#include "stack.h"


int main( int argc, char* argv [ ] )
{

#if 1 
   stack s1 = { 4, 2, 1 };
   stack s2 = { 8, 7, 4, 3, 0 };
   stack s4(s1);   
   for( size_t i = 0; i < 40; ++ i )
   {
      s1. push( i*i ); 
      s2 = s1;
 
   }

   double sum = 0;
   while( s2. size( ))
   {
      stack s3 = s2;
      sum += s3. peek( );
      s2. pop( );
   }
   std::cout << "the sum is " << sum << "\n";
   std::cout << "   should be 3.32834e+08\n"; 

  s4.push(8);
  s4.push(3);
  s1.push(3);
  s1.print(std::cout);
  std::cout<<s1.peek()<<"\n";
  s4.print(std::cout);
  
  s1.reset(5);
  s1.push(6);
  s1.print(std::cout);
  

  s2 = s1; 

  s1.clear();
  s2.pop();
  s2.pop();
  s2.print(std::cout);
  std::cout<<s1.size()<<"\n";
  std::cout<<s2.size()<<"\n";
  std::cout<<s1.empty()<<"\n";
  std::cout<<s4.peek()<<"\n";

  s1.push(3);
  s1.push(22);
  s1.print(std::cout);
  
  return 0;
#endif 
}

