//
// Created by erhan güven on 3.08.2023.
//

#ifndef EMPYRIA_UDPCLIENT_H
#define EMPYRIA_UDPCLIENT_H

#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include <functional>
#include <vector>
#include <glm/glm.hpp>

#define BUFFER_SIZE 512

namespace Engine
{

class ClientJoinMessage
{
    char msg[41] = "WHello server, I am the clientest client";
};

class UdpClient
{
public:
    void init();

    inline static UdpClient* getInstance()
    {
        if(instance == nullptr)
        {
            printf("new udpclient instance");
            instance = new UdpClient;
        }
        return instance;
    }

    template<class T>
    void sendData(T data)
    {
        sendto(sockfd, &data, sizeof(data), 0, (struct sockaddr*)NULL, sizeof(servaddr));
    }

    void listenData();

    void closeSocket();


    void registerOnReceiveData(std::function<void(char[], int, int)>& listener)
    {
        onReceiveDataEvents.push_back(listener);
    }

private:
    std::vector<std::function<void(char[], int, int)>> onReceiveDataEvents;

    void receivedData(char[], int, int);

    inline static UdpClient* instance;
    sockaddr_in servaddr;
    int sockfd;

};

} // Engine

#endif //EMPYRIA_UDPCLIENT_H