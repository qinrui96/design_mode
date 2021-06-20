#include "component.h"
void Composit::operator() ()
{
    if(member.size() == 0)
        return ;
    for(auto &item:member)
    {
        
        if(item == member.back())
        {
            (*item)();
        }
        else
        {
            (*item)();
        }
    }
}