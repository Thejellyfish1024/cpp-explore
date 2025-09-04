#include <stdio.h>
#define baseIp 0xC0A80000

struct LAN
{
    int lanId;
    int subnetMask;
    int hosts;
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
            if (lans[j].hosts < lans[j + 1].hosts)
            {
                struct LAN temp = lans[j];
                lans[j] = lans[j + 1];
                lans[j + 1] = temp;
            }
    }
}

int main()
{
    int totalLans;
    int totalHosts = 0;
    printf("Enter the number of Lans: ");
    scanf("%d", &totalLans);

    struct LAN lans[totalLans];

    for (int i = 0; i < totalLans; i++)
    {
        printf("Enter the number of hosts for LAN%d = ", i + 1);
        scanf("%d", &lans[i].hosts);
        totalHosts += lans[i].hosts;
        lans[i].lanId = i + 1;
    }

    int hostBits = 0;
    while ((1 << hostBits) < totalHosts)
        hostBits++;

    int baseMask = 32 - hostBits;

    printf("\nMinimum network needed for all LANs: ");
    printIP(baseIp);
    printf(" /%d\n", baseMask);

    sortLANs(lans, totalLans);

    unsigned int currentIp = baseIp;

    for (int i = 0; i < totalLans; i++)
    {
        int hosts = lans[i].hosts + 2;
        int bits = 0;
        while ((1 << bits) < hosts)
            bits++;
        lans[i].subnetMask = 32 - bits;
        lans[i].requiredHosts = (1 << bits);
        lans[i].network = currentIp;
        lans[i].broadcast = currentIp + lans[i].requiredHosts - 1;
        currentIp = lans[i].broadcast + 1;
    }

    printf("\nLAN    Network Address       Broadcast Address      Valid Host Range       Subnet Mask\n");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalLans; i++)
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
}