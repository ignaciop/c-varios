echo ""
echo "Which number am I thinking? [0, 32767]"
answer=$RANDOM
tries=0
echo -n " Try to guess : "
while read myAnswer; do
	tries=$((tries + 1))
	if [ $myAnswer -eq $answer ]; then
		echo ""
		echo "You won!"
		echo ""
		break
	elif [ $myAnswer -gt $answer ]; then
		echo -n "Too large! Try again: "
	else
		echo -n "Too small! Try again: "
	fi
	
done
echo "Number of tries: $tries"