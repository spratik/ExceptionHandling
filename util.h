#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <string>

#define THROW_EXCEPTION(exception_type, ...) \
		throw   util :: assertedException<exception_type>(__FILE__, to_string(__LINE__), __VA_ARGS__);


#define ASSERT_OR_THROW(predicate, ...) \
		if(!predicate) \
			THROW_EXCEPTION(__VA_ARGS__)

#define ASSERT_OR_THROW_SIMPLE(predicate) ASSERT_OR_THROW(predicate, std::runtime_error, "predicate is false: " #predicate)

namespace util
{

	template<typename T>
	class assertedException : public T
	{	
		std :: string  m_lineNo;
		std :: string m_fileName;
		public : 
		 // std::exception has a destructor that is declared such that no exceptions can be thrown out of it
		 /// If you complie with  c++11 compiler no need to meniton thow() otherwise need to mention
		 virtual ~assertedException() throw()  {}
		 	assertedException(std :: string fileName, std :: string lineNo, std :: string msg) 
			: T(fileName + ":" + lineNo + ":" + msg),
			  m_lineNo(lineNo),
			  m_fileName(fileName)
			 {}
	};

}
//THROW_EXCEPTION(std :: logic_error, "pratik")