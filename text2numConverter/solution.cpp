

//

//

//

#include <iostream>

using std::cout;
using std::endl;

#define CHECK(x) cout << x << " <> " << (x) << endl

int main(int argc, char const *argv[])
{
    CHECK("1234");
    CHECK("12  34");
    CHECK("87654");
    CHECK("-7654");
    
    return 0;
}
