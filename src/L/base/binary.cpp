#include <L/base/binary.hpp>
namespace L{
    namespace Base{
        bool IsLittleEndian(){
            int n = 1;
            return (*(char*) &n == 1);
        }
    }
}
