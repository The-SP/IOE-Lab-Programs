# Compare two strings
#!/bin/bash

echo "Enter the first string:"
read str1
echo "Enter the second string:"
read str2
if [ $str1 = $str2 ] 
then
    echo "Strings are equal."
else
    echo "Strings are unequal."
fi