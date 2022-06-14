#include "st_class.h"
using std::string;

STClass::STClass() : Variable() {}
STClass::STClass(string name, string type) : Variable(std::move(name), std::move(type), "Class") {}

std::unordered_map<std::string, std::shared_ptr<Method>> STClass::getMethods() const {
    return this->methods;
}

void STClass::addMethod(const std::shared_ptr<Method> &method) {
    auto method_pair = this->methods.insert({method->getName(), method});
    if (!method_pair.second) {
        std::cerr << "The method " << method->getName() << " already exists in the class!" << std::endl;
    }
}

std::optional<std::shared_ptr<Method>> STClass::lookupMethod(const string &name) const {
    auto iterator = this->methods.find(name);
    if (iterator != this->methods.end()) {
        return iterator->second;
    } else {
        return std::nullopt;
    }
}
