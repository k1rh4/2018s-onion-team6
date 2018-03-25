#ifndef MSGSERVER_H
#define MSGSERVER_H

#include<iostream>
#include<cstdlib>
#include <cstring>
#include <thread>
#include <unordered_map>
#include "config.h"
#include "serversocket.h"
#include "clientsocket.h"

#include "user_info.h"
extern UserInfo* myInfo;
extern unordered_map<string, UserInfo*> UserInfoMap;

class MsgServer
{
public:
    MsgServer();
    ~MsgServer();
    void RecvServer();
    int MsgClient(string ip, string msg);
    void Start();
    void Worker(ClientSocket* client_sock);
    int PGPDecrpyt(string msg);

private:
    ClientSocket * p_client_sock;
    ServerSocket * p_server_sock;
};

#endif // MSGSERVER_H