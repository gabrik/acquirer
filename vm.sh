#!/bin/sh

kvm -name vm1 -m 256 -net bridge,br=br0,name=br0 -net nic,model=virtio,netdev=mynet0 -netdev bridge,id=mynet0 -kernel acquirer.bin -append  '{  "rc": [{"bin" : "hello.bin",,"argv" : ["192.168.34.1",,"50040"],,}],,"net":{"if":"vioif0",,"type":"inet",,"method":"dhcp"}},,'



