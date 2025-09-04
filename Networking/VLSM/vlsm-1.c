#include <stdio.h>

#define baseIp 0xC0A80000

struct LAN
{
    int lanId;
    int hosts;
    int subnetMask;
    int requiredHosts;
    unsigned int network;
    unsigned int broadcast;
};

void printIP(unsigned int ip)
{
    printf("%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

void sortLANs(struct LAN lans[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lans[j].hosts < lans[j + 1].hosts)
            {
                struct LAN temp = lans[j];
                lans[j] = lans[j + 1];
                lans[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of LANs: ");
    scanf("%d", &n);

    struct LAN lans[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number of hosts for LAN %d: ", i + 1);
        scanf("%d", &lans[i].hosts);
        lans[i].lanId = i + 1;
    }

    sortLANs(lans, n);

    unsigned int currentIP = baseIp;

    for (int i = 0; i < n; i++)
    {
        int totalHosts = lans[i].hosts + 2;
        int bits = 0;
        while ((1 << bits) < totalHosts)
            bits++;

        lans[i].subnetMask = 32 - bits;
        lans[i].requiredHosts = (1 << bits);
        lans[i].network = currentIP;
        lans[i].broadcast = currentIP + lans[i].requiredHosts - 1;

        currentIP = lans[i].broadcast + 1;
    }

    printf("\nLAN    Network Address       Broadcast Address      Valid Host Range       Subnet Mask\n");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("LAN%-3d   ", lans[i].lanId);
        printIP(lans[i].network);
        printf("       ");
        printIP(lans[i].broadcast);
        printf("       ");
        printIP(lans[i].network + 1);
        printf(" - ");
        printIP(lans[i].broadcast - 1);
        printf("       ");
        printf("/%d\n", lans[i].subnetMask);
    }

    return 0;
}
