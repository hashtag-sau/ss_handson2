/*
============================================================================
Name : 34.c
Author : Saurabh Dubey
Description :Write a program to create a concurrent server. 
              b.Use `pthread_create`
Date: 20th sep, 2024.
============================================================================
*/
//this code is mostly taken with help of chatgpt, however i tried my best to understand the working of code.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read data from the client
    bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0'; // Null-terminate the string
    printf("Received: %s\n", buffer);

    // Send a response back to the client
    const char *response = "Hello from the server!";
    write(client_socket, response, strlen(response));

    // Close the client socket
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr;

    // Create a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Server listening on port %d...\n", PORT);

    pthread_t tid;
    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Handle error and keep running
        }
        
        int cs = client_socket;
        pthread_create(&tid,NULL,handle_client,&cs);
    }

    close(server_socket); // Close the server socket (never reached)
    return 0;
}

// Server listening on port 8080...
// Received: Hello from client!

