#include <L/ast/operators/operator.hpp>
namespace L{
    namespace AST{
        class PlusOperator: public OperatorNode{
        public:
            unsigned int getLevel(){
                return 4;
            }
            PlusOperator(){}
            PlusOperator(Number first_):first(first_){}
            Number first;
            Number last;
        }
        class MinusOperator: public OperatorNode{
        public:
            unsigned int getLevel(){
                return 4;
            }
            MinusOperator(){}
            MinusOperator(Number first_):first(first_){}
            Number first;
            Number last;
        }
        class AsteriskOperator: public OperatorNode{
        public:
            unsigned int getLevel(){
                return 4;
            }
            AsteriskOperator(){}
            AsteriskOperator(Number first_):first(first_){}
            Number first;
            Number last;
        }
        class SlashOperator: public OperatorNode{
        public:
            unsigned int getLevel(){
                return 4;
            }
            SlashOperator(){}
            SlashOperator(Number first_):first(first_){}
            Number first;
            Number last;
        }
    }
}