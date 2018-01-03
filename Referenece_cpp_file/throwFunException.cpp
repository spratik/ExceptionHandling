// exception_specification.cpp  
// compile with: /EHs  
#include <stdio.h>  
  
void handler() {  
   printf("in handler\n");  
}  
 
/// will throw only int
void f1(void) throw(int) {  
   printf("About to throw 1\n");  
   if (1)  
      throw 10;  
}  
  
 /// will throw nothing 
void f5(void) throw() {  
   try {  
      f1();  
   }  
   catch(...) {  
      handler();  
    }  
}  
  
// invalid, doesn't handle the int exception thrown from f1()  
// void f3(void) throw() {  
//   f1();  
// }  
  
  
// only valid if compiled without /EHc   
// /EHc means assume extern "C" functions don't throw exceptions  
void f4(void) {  
   f1();  
}  
  
int main() {  
    
   try {  
      f4();  
   }  
   catch(...) {  
      printf("Caught exception from f4\n");  
   }  
   f5();  
}  