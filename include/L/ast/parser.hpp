#include <L/ast/declare.hpp>
#include <L/ast/value.hpp>
#include <L/ast/operators/mathBase.hpp>
#include <stack>
namespace L{
    namespace AST{
        enum class Brackets{
		    OpenBrace, CloseBrace,
		    OpenParen, CloseParen,
		    OpenBracket, CloseBracket,
        };
        class Parser{
        private:
            std::stack<std::shared_ptr<Node>> lackStack;
            std::stack<Brackets> bracketStack;
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