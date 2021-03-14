#include <L/ast/ast.hpp>
namespace L{
    namespace AST{
        class VariableDeclare: public Node{
        public:
            VariableDeclare(unsigned long long name_, Token type_, std::shared_ptr<Node> value_): 
            Node(NodeKind::DeclareVariable),
            name(name_),
            type(type_),
            value(value_){
            }
            ~VariableDeclare(){}
            unsigned long long name;
            Token type;
            std::shared_ptr<Node> value;
        };
    }
}