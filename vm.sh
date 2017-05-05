#!/bin/sh

kvm -name vm1 -m 256 -net bridge,br=s1-br0,name=s1-br0 -net nic,model=virtio,macaddr=DE:AD:BE:EF:00:AA,netdev=mynet0 -netdev bridge,id=mynet0,br=s1-br0 -kernel acquirer.bin -append  '{  "rc": [{"bin" : "hello.bin",,"argv" : ["192.168.2.2",,"50040"],,}],,"net":{"if":"vioif0",,"type":"inet",,"method":"dhcp"}},,'
