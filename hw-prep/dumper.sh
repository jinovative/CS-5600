#!/bin/bash

./arger "$@"
if [ $? -ne 0 ]; then
    echo "Error occurred!"
else
    echo "Command executed successfully."
fi
