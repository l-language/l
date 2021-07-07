#include <L/ast/declare.hpp>
#include <L/ast/value.hpp>
namespace L{
    namespace AST{
        class Parser{
        private:
            Lexer lexer;
            Token current;
            Token next(){return current = lexer();}
        public:
            Parser(std::ifstream& fin):lexer(fin){}
            ~Parser(){}
            std::shared_ptr<Node> readKeyword();
            std::shared_ptr<Node> readIdentifier();
            std::shared_ptr<Node> readOperator();
            std::shared_ptr<Node> operator()();
            bool isEnd(){return lexer.isEnd();}
        };
    }
}