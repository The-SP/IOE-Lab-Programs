#!/bin/bash
# Signal Handling

echo "Program for performing KILL operations"
ps

echo "Enter the pid"
read pid

kill -9 $pid
echo "Finished"