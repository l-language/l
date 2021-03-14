#pragma once
#include <L.hpp>
#include <L/lexer.hpp>
#include <memory>
namespace L{
    namespace AST{
        enum class NodeKind{
            MainNode,
            DeclareVariable,
            StatementBlock,
        };
        class Node{
        private:
        public:
            Node(NodeKind kind_): kind(kind_){}
            virtual ~Node(){}
            NodeKind kind;
        };
    }
}
