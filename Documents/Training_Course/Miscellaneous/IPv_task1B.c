#include <stdio.h>
#include <unistd.h>         // for close()
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

    int sd = socket(AF_INET, SOCK_STREAM, 0 ); 
    if (sd < 0) {
        perror("socket");
        return 1;
    }

    char buffer[1024];
    // char ip_str[INET_ADDRSTRLEN];  // not needed unless printing client IP

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("bind");
        return 1;
    }

    if (listen(sd, 1) < 0){
        // 1 is the backlog number of pending connections the OS 
        // will queue before you call accept(). Can be set to anything i.e 128
        perror("listen");
        return 1;
    }

    int client_sd = accept(sd, NULL, NULL);
    // sd is the listening socket, the one passed to listen().
    // accept will return client_sd (only used for this 1 stage)
    // client_sd is now the socket for the connected client

    if (client_sd < 0) {
        perror("accept");
        return 1;
    }

    // Open a file to store the received data
    FILE *fp = fopen("output.txt", "wb");
    if (!fp) {
        perror("fopen");
        close(client_sd);
        close(sd);
        return 1;
    }

    int bytes;

    // Receive the file in chunks until the client closes the connection
    while ((bytes = recv(client_sd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
    }

    fclose(fp);
    close(client_sd);
    close(sd);

    // Now print the contents of the file
    fp = fopen("output.txt", "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    printf("Received file contents:\n");

    while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        fwrite(buffer, 1, bytes, stdout);
    }

    fclose(fp);
}
