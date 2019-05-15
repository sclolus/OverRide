#!/bin/bash

if [ -z $PROJECT_PATH ]
then
	echo "PROJECT_PATH was not set";
	exit 1;
fi

if [ -z $PREVIOUS_LEVEL ]
then
	echo "PREVIOUS_LEVEL was not set";
	exit 1;
fi

if [ -z $CURRENT_LEVEL ]
then
	echo "CURRENT_LEVEL was not set";
	exit 1;
fi

if [ -z $VM_IP ]
then
	echo "VM_IP was not set";
	exit 1;
fi

ssh.sh "chmod +w ."
scp_pull.sh $CURRENT_LEVEL
scp_push.sh `which bprint.sh`
scp_push.sh `which shellcode.sh`
scp_push.sh `which gdb.script`

