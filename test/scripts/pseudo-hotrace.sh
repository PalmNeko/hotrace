#!/bin/bash

# hotrace

declare -gA Map

KEY=""
while read LINE; do
    if [ -z "$LINE" ]; then
        break
    elif [ -n "$KEY" ]; then
        Map["$KEY"]="$LINE"
        KEY=""
    else
        KEY="$LINE"
    fi
done

if [ -n "$KEY" ]; then
    echo "No Value" > /dev/stderr
    exit 1
fi

while read LINE; do
    if [ -z "$LINE" ]; then
        continue
    elif [ -z "${Map["$LINE"]}" ]; then
        echo "$LINE: Not found." > /dev/stderr
    else
        echo "${Map["$LINE"]}"
    fi
done
