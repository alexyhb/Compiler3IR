#include "vm.h"
VM::VM(){

}
using namespace std;
void VM::translate(){
    string s;
    ifstream in;
    in.open("out.class", std::ios::in);
    stack<string> stk,temp;
    size_t npos = -1; 
while(getline(in,s)){
   // LOG_INFO(stk.top()<<" "<<s);
    size_t pos = s.find(" ");  
    size_t ifNot= s.find("inot ");
   
    if(pos!=npos){
        string value = s.substr(pos);
            // LOG_INFO("iload"<< value << " "<<stk.size());

        stk.push(value);
    }else{
        if(s=="istore"){
            // LOG_INFO("istore1 :"<<stk.size());
            string res=temp.top();
            temp.pop();
            stk.push(res);
            // LOG_INFO("istore2 : "<<stk.size());

        }else if(s=="print"){
            // LOG_INFO("print"<<stk.size());

            string res=stk.top();
            stk.pop();
            cout<<res<<endl;
        } 
        else{
           
            // LOG_INFO("calc1 :"<<stk.size());
            string right=stk.top();
            stk.pop();
            string left=stk.top();
            stk.pop();
            string res=this->cacl(left,right,s);
            temp.push(res);
            // LOG_INFO("calc2 :"<<stk.size()<< " " << temp.size());

        }
        
    }
    if(ifNot!=npos){
             //LOG_INFO("inot!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1"<<stk.size());
            string value=s.substr(ifNot);
            
            string res=stk.top();
            //LOG_INFO(res);
            string result;
            if(res==" true"){
                result="false";
            }else{
                result="true";
            }
          
            //LOG_INFO((res=="true")<<" " <<result);
            stk.pop();
            stk.push(result);
            
        }
}

    in.close();
}

string VM::cacl(string left,string right, string oper){
    string res;
    if(oper=="ilgt"){
            // LOG_INFO("ilgt");

        res=(stoi(left))< (stoi(right))? "true": "false";
    }
    if(oper=="ilst"){
            // LOG_INFO("ilst");

        res=(stoi(left))> (stoi(right))? "true": "false";
    }
    if(oper=="iadd"){
            // LOG_INFO("iadd");

        int l=stoi(left);
        int r=stoi(right);
        res=to_string( l+r);
    }
    if(oper=="isub"){
            // LOG_INFO("isub");

        int l=stoi(left);
        int r=stoi(right);
        res=to_string( l-r);
    }
    if(oper=="imul"){
            // LOG_INFO("imul");

    int l=stoi(left);
        int r=stoi(right);
        res=to_string( l*r);
    }
    if(oper=="idiv"){
            // LOG_INFO("idiv");

        int l=stoi(left);
        int r=stoi(right);
        res=to_string( l/r);
    }
    if(oper=="ior"){
            // LOG_INFO("ior");

        bool l= left=="true" ? true: false;
        bool r= right=="true" ? true: false;
        string str=(l||r) ? "true": "false";
        res=str;

    }
        if(oper=="iequ"){
            // LOG_INFO("iequ");

        bool l= left=="true" ? true: false;
        bool r= right=="true" ? true: false;
        res=( l==r)?"true": "false";

    }
    
    if(oper=="iand"){
            // LOG_INFO("iand");

        bool l= left=="true" ? true: false;
        bool r= right=="true" ? true: false;
        string str=(l||r) ? "true": "false";

        res=to_string( l&&r);
    }
    
    return res;
}

