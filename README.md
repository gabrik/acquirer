Acquirer - VNF
===================


General Info
----------------

This simple **VNF** (*Virtual Network Function*), provide a repeater for UDP/RTP Video Stream inside an SDN/NFV platform.
Developed to be shown as part of a demo of a paper.

----------

How it works
-----------------

Simply listen to all interfaces on port 50040 and repeat all UDP message that receive to a fake ip address (*the real destination is orchestrated by the SDN Controller*)

----------


How to build
-------------
Uses only standard libs, you can use makefile for build

```
user@unix:~/acquirer$ make
```
This will create a file named **acquirer** inside the repo directory.
To run simply use

```
user@unix:~/acquirer$ ./acquirer <fake destination> <udp port> -d (optional for debug)
```

To build as unikernel

```
user@unix:~/acquirer$ make unikernel
```

Then you can edit vm.sh file for use the correct bridge interface, and the arguments, then you can start a unikernel by typing

```
user@unix:~/acquirer$ sudo ./vm.sh
```

This code as the possibility to be build as a unikernel, by using [rumprun](https://github.com/rumpkernel/rumprun)