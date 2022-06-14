#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <fstream>
#include <string.h>
#include "method.h"
#include "parameter.h"
#include "st_class.h"
#include "symbol_table.h"
#include "variable.h"
#include "cfg.h"
#define LOG_INFO(x) std::cout<<(strchr(__FILE__,'/')==NULL?__FILE__:strchr(__FILE__,'/')+1)<<":"<<__FUNCTION__<<":"<<__LINE__<<": "<<x<<std::endl

class Node {
protected:
    std::size_t id = 0;
    std::string type, value;

public:
    std::deque<std::shared_ptr<Node>> children;
    inline static SymbolTable st = SymbolTable();

    Node();
    Node(std::string t, std::string v);
    virtual ~Node() = default;
    void printInf();

    void setId(std::size_t n_id);
    void setType(std::string n_type);
    void setValue(std::string n_value);
    std::size_t getId() const;
    std::string getType() const;
    std::string getValue() const;

    void generateAST(std::ofstream *outStream, std::size_t &count);

    void buildST(std::ofstream *outStream);
    virtual std::optional<std::string> generateST();

    void semanticAnalysis();
    virtual std::optional<std::string> checkSemantics();

    virtual void* genIR(std::map<std::string ,ControlFlowGraph*> &cfgs);
    virtual void* genIR(BasicBlock *currentBlock);
    static void printErrMsg(const std::string &message);
};

#endif
