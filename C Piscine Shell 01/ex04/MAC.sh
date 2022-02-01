ifconfig -a | grep ether | grep -v auto | awk '{ print $2 }'
