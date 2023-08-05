//
// Created by erhan güven on 3.08.2023.
//

#include "UdpClient.h"
#include <future>

#define PORT 5000
#define MAXLINE 1000

extern bool isRunning;

namespace Engine
{

void UdpClient::init()
{
    char buffer[100];
    char *message = "Hello Server";

    // clear servaddr
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;

    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        exit(0);
    }

    ClientJoinMessage joinMessage;
    sendData(joinMessage);

    listenData();
}

void UdpClient::listenData()
{
    while(isRunning)
    {
        char buffer[BUFFER_SIZE];
        int n;
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL);
        printf("Received message: %s\n", buffer);

        auto t = std::async(&UdpClient::receivedData, this, buffer, BUFFER_SIZE, n);
    }
}

void UdpClient::closeSocket()
{
    shutdown(sockfd, SHUT_RDWR);
    close(sockfd);
}

void UdpClient::receivedData(char * buffer, int bufferSize, int n)
{
    for(auto onReceiveData : onReceiveDataEvents)
        onReceiveData(buffer, bufferSize, n);
}

} // Engine