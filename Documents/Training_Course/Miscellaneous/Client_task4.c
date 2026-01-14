#include <stdio.h>
#include <string.h>     
#include <unistd.h>    
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    int sd = socket(AF_INET, SOCK_STREAM, 0);


    if (sd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);

    if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        perror("connect");
        return 1;
    }



    char buffer[1024];

    while (1) {

        int bytes = recv(sd, buffer, sizeof(buffer)-1, 0);


        if (bytes <= 0) {
            perror("recv");
            break;
        }

        buffer[bytes] = '\0';  

        printf("Current time from server: %s\n", buffer);

    }

    close(sd);
    return 0;
}