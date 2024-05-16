for FILE in $(cat ./filewitharray.txt)
do
	cp ${FILE} ~/ros2/src/apollo-ros2/${FILE}
done
