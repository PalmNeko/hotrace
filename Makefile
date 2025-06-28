

.PHONY: test
test: test_norm test_build

test_build:
	make -C submit
	echo 'Build OK'

test_norm:
	! norminette submit | grep -v "OK"
	echo 'Norminette OK'
