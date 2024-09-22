/*
============================================================================
Name : 34.c
Author : Saurabh Dubey
Description :Write a program to create a concurrent server. 
             a.Use fork 
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

void handle_client(int client_socket) {
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

    // Create a socket
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

    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Handle error and keep running
        }

        // Fork a new process to handle the client
        if (fork() == 0) {
            close(server_socket); // Child doesn't need the listening socket
            handle_client(client_socket); // Handle the client
            exit(0); // Exit child process after handling
        } else {
            close(client_socket); // Parent doesn't need the client socket
        }
    }

    close(server_socket); 
    return 0;
}
