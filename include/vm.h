#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <ostream>

#include <limits> 
#include <cstring>
#include <sstream>
#include <stack> //栈容器头文件
#define LOG_INFO(x) std::cout<<(strchr(__FILE__,'/')==NULL?__FILE__:strchr(__FILE__,'/')+1)<<":"<<__FUNCTION__<<":"<<__LINE__<<": "<<x<<std::endl

class VM{
public: 
    VM();
    void translate();
    std::string cacl(std::string left,std::string right,std::string oper);
   

};