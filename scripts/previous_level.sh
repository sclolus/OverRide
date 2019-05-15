#!/bin/bash

if [ -z $CURRENT_LEVEL ]
then
	echo "CURRENT_LEVEL was not set";
	exit 1;
fi

LEVELS=(level0 level1 level2 level3 level4 level5 level6 level7 level8 level9 bonus0 bonus1 bonus2 bonus3)

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
