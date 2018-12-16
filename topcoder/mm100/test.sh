for i in {1..500}
do
  java -jar tester.jar -exec "python SameColorPairs.py" -seed $i -novis
done
