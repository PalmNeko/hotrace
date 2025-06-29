#!/bin/bash

function main() {
	local key_size="${1:-1000}"  # Default key size
	local search_size="${2:-100}"  # Default search size
	local max_key_length="${3:-20}"

	if [ "$#" -gt 3 ] || [ "$1" = "--help" ]; then
		echo "Usage: $0 [<key_size> <search_size> [<max_key_length>]]"
		exit 1
	fi

	generate_large_file "$key_size" "$search_size" "$max_key_length"
}

function generate_large_file() {
	local key_size="$1"
	local search_size="$2"
	local max_key_length="${3:-20}"

	if [ -z "$key_size" ] || [ -z "$search_size" ]; then
		echo "Usage: $0 <key_size> <search_size> [<max_key_length>]"
		exit 1
	fi

	local -ga ary
	local rand_length=12 align_length=10
	for i in $(seq 1 "$key_size"); do
		local rand_length=$((RANDOM % $max_key_length + 1))
		local key="$(openssl rand -base64 "$rand_length" | fold -w "$rand_length" | head -1)"
		ary+=("$key")
		echo "$key"
		echo "$key"
	done

	echo

	for i in $(seq 1 "$search_size"); do
		local key="${ary[RANDOM % ${#ary[@]}]}"
		echo "$key"
	done
}

main "$@"
