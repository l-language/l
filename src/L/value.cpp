#include <L/value.hpp>
namespace L{
    namespace Value{
        Object::Object(Object& obj){
            obj.count++
        }
    }
}