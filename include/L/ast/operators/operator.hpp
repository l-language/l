#include <L/ast/declare.hpp>
namespace L{
    namespace AST{
        class OperatorNode:public Node{
        private:
        public:
            virtual unsigned int getLevel() = 0;
            OperatorNode(){}
            ~OperatorNode(){}
        }
    }
}