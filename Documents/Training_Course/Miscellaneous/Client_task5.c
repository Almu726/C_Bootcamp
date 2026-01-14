#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    int sd = socket(AF_INET, SOCK_DGRAM, 0);


    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // the register packet
    char msg[] = "register";
    sendto(sd, msg, strlen(msg), 0,
    (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("Registered with server. Waiting for time updates...\n");

    char buffer[1024];
    socklen_t server_len = sizeof(server_addr);

    while (1) {

        int bytes = recvfrom(sd, buffer, sizeof(buffer)-1, 0,
        (struct sockaddr*)&server_addr, &server_len);

        if (bytes > 0) {
            buffer[bytes] = '\0';
            printf("Current time from server: %s\n", buffer);
        }
    }

    close(sd);
    return 0;
}
