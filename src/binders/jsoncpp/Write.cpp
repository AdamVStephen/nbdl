//this file is no longer used
#include<stdexcept>
#include "Write.h"

namespace nbdl {
namespace binders {
namespace jsoncpp {

//todo replace this stuff with a template
void Write::bind(const std::string name, bool & field) 
{ 
	jsonVal[name] = field; 
}
void Write::bind(const std::string name, unsigned int & field) 
{ 
	jsonVal[name] = field; 
}
void Write::bind(const std::string name, int & field) 
{ 
	jsonVal[name] = field; 
}
void Write::bind(const std::string name, double & field) 
{ 
	jsonVal[name] = field; 
}
void Write::bind(const std::string name, std::string & field) 
{ 
	jsonVal[name] = field; 
}

}//jsoncpp
}//binders
}//nbdl
