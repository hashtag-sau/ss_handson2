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
    int server_fd, new_socket_fd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(PORT);

    // Bind socket to port
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 1); // Listen for 1 connection

    printf("Server listening on port %d...\n", PORT);

    // Accept a client connection
    new_socket_fd = accept(server_fd, NULL, NULL);

    // Read message from client
    read(new_socket_fd, buffer, BUFFER_SIZE);
    printf("Received: %s\n", buffer);

    // Send response to client
    char *response = "Hello from server!";
    send(new_socket_fd, response, strlen(response), 0);

    // Close sockets
    close(new_socket_fd);
    close(server_fd);
    return 0;


}

// Server listening on port 8080...
// Received: Hello from client!


