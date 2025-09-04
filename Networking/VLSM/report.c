
// // Switch(config)#vlan 10
// // Switch(config-vlan)#name Accounts
// // Switch(config-vlan)#exit
// // Switch(config)#vlan 20
// // Switch(config-vlan)#name Sales
// // Switch(config-vlan)#exit
// // Switch(config)#interface range fastEthernet 0/2-3
// // Switch(config-if-range)#switchport mode access
// // Switch(config-if-range)#switchport access vlan 10
// // Switch(config-if-range)#exit
// // Switch(config)#interface range fastEthernet 0/4-5
// // Switch(config-if-range)#switchport mode access
// // Switch(config-if-range)#switchport access vlan 20
// // Switch(config-if-range)#exit
// // Switch(config)#interface fastEthernet 0/24
// // Switch(config-if)#switchport mode trunk
// // Switch(config-if)#switchport trunk allowed vlan 10,20
// // Switch(config-if)#no shutdown
// // Switch(config-if)#switchport trunk native vlan 1

// // ! Subinterface for VLAN 10
// // Router(config)#interface gigabitEthernet 0/0.10
// // Router(config-subif)#encapsulation dot1Q 10
// // Router(config-subif)#ip address 192.168.1.1 255.255.255.192
// // Router(config-subif)#no shutdown
// // Router(config-subif)#exit

// // ! Subinterface for VLAN 20
// // Router(config)#interface gigabitEthernet 0/0.20
// // Router(config-subif)#encapsulation dot1Q 20
// // Router(config-subif)#ip address 192.168.1.65 255.255.255.192
// // Router(config-subif)#no shutdown
// // Router(config-subif)#exit

// // ! Enable the main physical interface
// // Router(config)#interface gigabitEthernet 0/0
// // Router(config-if)#no shutdown
// // Router(config-if)#exit

// // Router>enable
// // Router#configure terminal

// // ! Exclude router and reserved IPs from DHCP pool
// // Router(config)#ip dhcp excluded-address 192.168.1.1 192.168.1.10
// // Router(config)#ip dhcp excluded-address 192.168.1.65 192.168.1.70

// // ! DHCP pool for VLAN 10
// // Router(config)#ip dhcp pool VLAN10-POOL
// // Router(dhcp-config)#network 192.168.1.0 255.255.255.192
// // Router(dhcp-config)#default-router 192.168.1.1
// // Router(dhcp-config)#dns-server 192.168.1.130
// // Router(dhcp-config)#exit

// // ! DHCP pool for VLAN 20
// // Router(config)#ip dhcp pool VLAN20-POOL
// // Router(dhcp-config)#network 192.168.1.64 255.255.255.192
// // Router(dhcp-config)#default-router 192.168.1.65
// // Router(dhcp-config)#dns-server 192.168.1.130
// // Router(dhcp-config)#exit

// // Router1(config)#router os
// // Router1(config)#router ospf 1
// // Router1(config-router)#rou
// // Router1(config-router)#router-id 1.1.1.1
// // Router1(config-router)#ne
// // Router1(config-router)#net
// // Router1(config-router)#network 192.168.1.0 0.0.0.63 ar
// // Router1(config-router)#network 192.168.1.0 0.0.0.63 area 0
// // Router1(config-router)#network 192.168.1.64 0.0.0.63 area 0
// // Router1(config-router)#network 192.168.1.140 0.0.0.63 area 0
// // Router1(config-router)#network 192.168.1.128 0.0.0.63 area 0

// // Router(config)#router rip
// // Router(config-router)#version 2
// // Router(config-router)#network 192.168.1.0
// // Router(config-router)#network 192.168.1.64
// // Router(config-router)#network 192.168.1.128
// // Router(config-router)#network 192.168.1.140

// ! Define access list to specify which IPs are allowed for NAT

// ! Configure NAT overload (PAT)

// Router(config)#ip route 209.165.200.224 255.255.255.248 209.165.201.17
// NAT-Router(config-router)#default-information originate