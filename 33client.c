/*
============================================================================
Name : 33.c
Author : Saurabh Dubey
Description :Write a program to communicate between two machines using socket.
Date: 20th sep, 2024.
============================================================================
*/

//this code is mostly taken with help of chatgpt, however i tried my best to understand the working of code.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation error\n");
        return 1;
    }

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Connect to localhost

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return 1;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    // Receive response from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);

    // Close socket
    close(sock);
    return 0;
}

// Message sent to server
// Response from server: Hello from server!
