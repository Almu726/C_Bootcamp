#include <stdio.h>
#include <string.h>     // for strlen()
#include <unistd.h>     // for close()
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    int sd = socket(AF_INET, SOCK_STREAM, 0);
    // "SOCK_STREAM" - tells to use TCP
    // TCP will auto be used when you call the functions for both
    // client and server e.g bind() and send() and connect() etc

    if (sd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;    

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr); // only use this function for client

    if (connect(sd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        perror("connect");
        return 1;
    }

    // Open the file we want to send
    FILE *fp = fopen("input.txt", "rb");
    if (!fp) {
        perror("fopen");
        close(sd);
        return 1;
    }

    char buffer[1024];
    size_t bytes;

    // Read the file in chunks and send each chunk
    while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        if (send(sd, buffer, bytes, 0) < 0) {
            perror("send");
            break;
        }
    }

    fclose(fp);
    close(sd);

    // The OS performs a TCP 3 way handshake
        // SYN ->
        // <- SYN-ACK
        // ACK ->

    // SYN -> (client sends a packet to the server)
    // <- SYN-ACK (server sends a packet back to the client, containing two flags)
    // SYN - i accept request, gives ISN
    // ACK - i acknowledge your SYN
    // ACK -> (client sends one final packet to server, saying i acknowledge your SYN)

    // SYN is a TCP Packet = Synchronize
    // ACK = Acknowledgement
    // SYN-ACK = Synchronize-Acknowledgement

    // sd here is the socket descriptor
    // connect() expects a pointer to a generic addr type which is done by casting 
    // sockaddr to the location of addr
    // checks if condition of less than 0 is met. 0 = success. -1 = fail
    // aka < 0 = did it fail?

    // perror prints a human readable error message
    // if connection fails, return 1 is used

    return 0;
}
