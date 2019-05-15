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

cat $PROJECT_PATH/$PREVIOUS_LEVEL/flag | pbcopy; ssh -p 4242 $CURRENT_LEVEL@$VM_IP $1
