

HOTRACE="../../submit/hotrace"
REF_EXEC="pseudo-hotrace.sh"
INPUT_DIR="../input-files"
OUTDIR="../output"
EXPECT_DIR="../expected"
TIME_DIR="../time"

function main() {
	parse_args "$@"
	initialize
	check_hotrace

	echo "Running Hotrace tests..."

	if [ "$METHOD" = "validate" ]; then
		TARGET_INPUT_FILES="$(find "$INPUT_DIR" -type f -name "large-file*")"
	elif [ "$METHOD" = "time" ]; then
		TARGET_INPUT_FILES="$(find "$INPUT_DIR" -type f -name "large-file*")"
	elif [ "$METHOD" = "leak" ]; then
		TARGET_INPUT_FILES="$(find "$INPUT_DIR" -type f -not -name "large-file*")"
	else
		echo "Error: Invalid method '$METHOD'. Please use 'validate' or 'time'."
		exit 1
	fi

	for input_file in $TARGET_INPUT_FILES; do
		if [[ -f "$input_file" ]]; then
			expected_file="$EXPECT_DIR/$(basename "$input_file")"
			if [ "$METHOD" = "validate" ]; then
				echo "Validating result for input file: $input_file"
				validate_result "$input_file"
			elif [ "$METHOD" = "leak" ]; then
				echo "Checking for memory leaks for input file: $input_file"
				leak_check "$input_file"
			elif [ "$METHOD" = "time" ]; then
				echo "Measuring time for input file: $input_file"
				measurement_time "$input_file"
			else
				echo "Unknown method: $METHOD. Please use 'validate' or 'time'."
				exit 1
			fi
		fi
	done

	echo "All tests completed successfully."
}

function usage() {
	echo "Usage: $0 [options] method"
	echo "Options:"
	echo "  -h, --help      Show this help message"
	echo "Methods:"
	echo "  validate        Validate the output of Hotrace against expected results"
	echo "  time            Measure the execution time of Hotrace"
	echo "  leak            Check for memory leaks in Hotrace execution"
}

function parse_args() {
	while [[ $# -gt 0 ]]; do
		case "$1" in
			-h|--help)
				usage
				exit 0
				;;
			*)
				break
				;;
		esac
		shift
	done
	METHOD="$1"
	if [[ -z "$METHOD" ]]; then
		echo "Error: No method specified. Please use 'validate' or 'time'."
		usage
		exit 1
	fi
	if [[ "$METHOD" != "validate" && "$METHOD" != "time" && "$METHOD" != "leak" ]]; then
		echo "Error: Invalid method '$METHOD'. Please use 'validate' or 'time' or 'leak'."
		usage
		exit 1
	fi
}

function initialize() {
	CUR_DIR=$(pwd)
	SCRIPT_DIR=$(cd $(dirname "$BASH_SOURCE[0]") && pwd)
	HOTRACE="$SCRIPT_DIR/$HOTRACE"
	REF_EXEC="$SCRIPT_DIR/$REF_EXEC"
	INPUT_DIR="$SCRIPT_DIR/$INPUT_DIR"
	EXPECT_DIR="$SCRIPT_DIR/$EXPECT_DIR"
	OUTDIR="$SCRIPT_DIR/$OUTDIR"
	TIME_DIR="$SCRIPT_DIR/$TIME_DIR"
}

function check_hotrace() {
	if [[ ! -x "$HOTRACE" ]]; then
		echo "Error: $HOTRACE is not executable or does not exist."
		exit 1
	fi
	if [[ ! -d "$INPUT_DIR" ]]; then
		echo "Error: Input directory '$INPUT_DIR' does not exist."
		exit 1
	fi
	if [[ ! -d "$EXPECT_DIR" ]]; then
		echo "Creating expected output directory '$EXPECT_DIR'."
		mkdir -p "$EXPECT_DIR"
	fi
	if [[ ! -d "$OUTDIR" ]]; then
		echo "Creating output directory '$OUTDIR'."
		mkdir -p "$OUTDIR"
	fi
	if [[ ! -x "$REF_EXEC" ]]; then
		echo "Error: Reference execution script '$REF_EXEC' is not executable or does not exist."
		exit 1
	fi
	if [[ ! -d "$TIME_DIR" ]]; then
		echo "Creating time measurement directory '$TIME_DIR'."
		mkdir -p "$TIME_DIR"
	fi
}

function validate_result() {
	local input_file="$1"
	local expected_file="$EXPECT_DIR/$(basename "$input_file")"
	local output_file="$OUTDIR/$(basename "$input_file")"

	if [[ ! -f "$expected_file" ]]; then
		echo 'Expected output file does not exist. Generating it...'
		make_expected "$input_file" "$expected_file"
	fi
	"$HOTRACE" < "$input_file" > "$output_file"
	if [[ $? -ne 0 ]]; then
		echo "Error: Hotrace execution failed for input file '$input_file'."
		exit 1
	fi
	if ! diff -q "$output_file" "$expected_file" > /dev/null; then
		diff -q "$output_file" "$expected_file"
		exit 1
	fi
	echo "Output matches expected output for input file '$input_file'."
}

function leak_check() {
	local input_file="$1"

	valgrind -q --leak-check=full --error-exitcode=223 "$HOTRACE" < "$input_file" > "$OUTDIR/$(basename "$input_file")"
	if [[ $? -eq 223 ]]; then
		echo "Error: Hotrace execution failed for input file '$input_file'."
		exit 1
	fi
	echo "Checking for memory leaks in input file '$input_file'..."
}

function measurement_time() {
	local input_file="$1"
	local expected_file="$EXPECT_DIR/$(basename "$input_file")"
	local time_file="$TIME_DIR/$(basename "$input_file").time"

	if [[ ! -f "$input_file" ]]; then
		echo "Error: Input file '$input_file' does not exist."
		exit 1
	fi

	if [[ ! -f "$expected_file" ]]; then
		echo "Expected output file '$expected_file' does not exist. Generating it..."
		make_expected "$input_file" "$expected_file"
	fi

	/usr/bin/time -qpo "$time_file" $HOTRACE  < "$input_file" > /dev/null
	if [[ $? -ne 0 ]]; then
		echo "Error: Hotrace execution failed for input file '$input_file'."
		exit 1
	fi
	echo "$input_file:"
	cat "$time_file"
	echo "Time measurement for '$input_file' completed. Results saved in '$time_file'."
}

function make_expected() {
	local input_file="$1"
	local expected_file="$2"

	if [[ ! -f "$input_file" ]]; then
		echo "Error: Input file '$input_file' does not exist."
		exit 1
	fi

	bash "$REF_EXEC" < "$input_file" > "$expected_file"
}

main "$@"
