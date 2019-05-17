#!/bin/bash

if [ -z $CURRENT_LEVEL ]
then
	echo "CURRENT_LEVEL was not set";
	exit 1;
fi

LEVELS=(level00 level01 level02 level03 level04 level05 level06 level07 level08 level09)

for level in {0..14}
do
	if [[ ${LEVELS[$level]} = $CURRENT_LEVEL ]]
	then
		PREVIOUS_LEVEL=${LEVELS[$(($level - 2))]}
		CURRENT_LEVEL=${LEVELS[$(($level - 1))]};
		break
	fi
done

echo "CURRENT_LEVEL is now $CURRENT_LEVEL"
cd $PROJECT_PATH/$CURRENT_LEVEL/
