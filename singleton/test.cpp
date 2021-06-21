#include<iostream>
#include"AgentManager.h"
#include<pthread.h>

void* func2(void *)
{
    AgentManager& agentmanager = (Singleton<AgentManager>::GetInstance());
    agentmanager.Add1();
}

void* func1(void *)
{
    AgentManager& agentmanager = (Singleton<AgentManager>::GetInstance());
    agentmanager.Add1();
}

int main()
{
    pthread_t pthread_id[10];
    
    pthread_create(&pthread_id[0], NULL, &func1, NULL);
    pthread_create(&pthread_id[1], NULL, &func2, NULL);
    
    for(int i=0;i<2;i++)
    {
        pthread_join(pthread_id[i], NULL);
    }

}