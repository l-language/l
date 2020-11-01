#pragma once
#include <L.hpp>
namespace L {
    namespace Value {
        class Object{
        private:
            Object* ref;
#ifdef L_USE_BIG_COUNT
            unsigned long long count;
#else
            unsigned long count;
#endif
        public:
            Object():count(1){}
            Object(Object&);
        };
    }
}