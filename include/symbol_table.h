#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "scope.h"

class SymbolTable {
private:
    std::shared_ptr<Scope> root;
    std::shared_ptr<Scope> current;

public:
    SymbolTable();
    virtual ~SymbolTable() = default;

    void enterScope();
    void exitScope();

    void setScopeTitle(const std::string &title);
    std::string getScopeTitle() const;
    std::string getScopeType() const;
    std::shared_ptr<Scope> getParentScope() const;

    void addRecord(const std::string &key, const std::shared_ptr<Record> &item);
    std::optional<std::shared_ptr<Record>> lookupRecord(const std::string &key) const;
    std::optional<std::shared_ptr<Record>> lookupRecordInRoot(const std::string &key) const;

    std::optional<std::shared_ptr<Scope>> lookupChildScope(const std::string &key) const;

    void printST(std::ofstream *outStream);
    void resetTable();
};

#endif