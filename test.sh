# colors
GREEN="\033[92m"
REDBG="\033[101m"
RED="\033[91m"
MUTED="\033[1;30m"
RESET="\033[0m"

# run diff check
if diff $2 temp > /dev/null ; then
	printf "${GREEN}✓${RESET}"
else
	echo "${RED}[KO] on test $1, check $2 for correct output\n${RESET}Your output:\n${MUTED}"
	cat -e temp
	echo ----- correct output -----
	cat -e $2
fi
rm -f temp

