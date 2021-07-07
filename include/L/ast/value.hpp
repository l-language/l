#pragma once
#include <L/ast/ast.hpp>
namespace L{
    namespace AST{
        class Number:public Node{
        private:
            std::size_t value;
        public:
            Number(std::size_t num): Node(NodeKind::Number),
            value(num) {
            }
        };
        class Double: public Node{
        private:
            double value;
        public:
            Double(double num): Node(NodeKind::Double),
            value(num){
            }
            ~Double(){}
        };
        class String:public Node{
        private:
            std::string value;
        public:
            String(std::string num): Node(NodeKind::String),
            value(num) {
            }
        };
    }
}