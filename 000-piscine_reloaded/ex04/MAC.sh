#!/bin/sh
# ifconfig -a | grep 'ether ' | tr -d " " | cut -c 7- 
ifconfig | grep "ether" | sed "s/ether //" | cut -c 2- | tr -d ' ' | cut -b 1-17
# ifconfig | grep -o -E '([[:xdigit:]]{2}:){5}[[:xdigit:]]{1,2}'
# ifconfig | grep ether | awk '{print $2}'
# ifconfig | grep ether | cut -b 8-
# ifconfig | grep "ether" -w | cut -d ' ' -f2