#include "mothed.h"

int main()
{
    Context mycontext({3,2,1,4,5});
    Strategy *s1 = new Strategy1;
    Strategy *s2 = new Strategy2;
    mycontext.SetStrategy(s1);
    mycontext.DoStrategy();
    mycontext.SetStrategy(s2);
    mycontext.DoStrategy();
}