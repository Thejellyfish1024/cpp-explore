#include <stdio.h>
#include <math.h>
#define baseIp 0xC0A80000

void printIP(unsigned int ip)
{
    printf("%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

int main()
{
    int n;
    printf("Enter number of LANs: ");
    scanf("%d", &n);

    int hosts[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number of hosts for LAN %d: ", i + 1);
        scanf("%d", &hosts[i]);
    }

    unsigned int currentIP = baseIp;

    printf("\nLAN    Network Address       Broadcast Address      Valid Host Range       Subnet Mask\n");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        int totalHosts = hosts[i] + 2;
        int bits = 0;

        while ((1 << bits) < totalHosts)
            bits++;

        int subnetMask = 32 - bits;

        unsigned int network = currentIP;
        unsigned int broadcast = currentIP + (1 << bits) - 1;

        printf("LAN%-3d   ", i + 1);
        printIP(network);
        printf("       ");
        printIP(broadcast);
        printf("       ");
        printIP(network + 1);
        printf(" - ");
        printIP(broadcast - 1);
        printf("       ");
        printf("/%d\n", subnetMask);

        // Move to the next network
        currentIP = broadcast + 1;
    }

    return 0;
}
