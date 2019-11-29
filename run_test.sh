
# config
TESTFOLDER="tests/normal/"
ADVANCEDFOLDER="tests/bonus/"
ADVANCEDTEST="1.txt 2.txt"
ANSWERFOLDER="../../answers/normal/"
ADVANCEDANSWERFOLDER="../../answers/bonus/"

# colors
GREEN="\033[92m"
MUTED="\033[1;30m"
Cyan="\033[1;36m"
RESET="\033[0m"
BOLD="\033[1m"

# normal tests
echo "${Cyan}<><><><><><><><><><><><><><><><><><><><><><>${RESET}"
echo "${Cyan}<><><> BUFFER $1 <><><>${RESET}"
echo "${Cyan}<><><><><><><><><><><><><><><><><><><><><><>${RESET}"
cd $TESTFOLDER
for FILE in *; do
	if [ -f "${FILE}" ]; then
		# run single test with open()
		printf "${GREEN}▹ Running on  \"${RESET}${BOLD}${FILE}${GREEN}\":${RESET}\n\n"
		../../a.out ${FILE} > temp
		sh ../../test.sh ${FILE} ${ANSWERFOLDER}${FILE}
		
		if [ "${FILE}" != "INVALID_FD" ]; then
			# run single test with stdin
			cat ${FILE} | ../../a.out > temp
			sh ../../test.sh ${FILE} ${ANSWERFOLDER}${FILE}
			echo ""
		fi
	fi
done
cd ../../
