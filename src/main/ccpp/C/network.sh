#/bin/bash

if [[ "$(uname)" != "Darwin" ]]; then
  brctl addbr br0
  ip addr flush dev eth0
  brctl addif br0 eth0
  tunctl -t tap0 -u $(whoami)
  brctl addif br0 tap0
  ifconfig eth0 up
  ifconfig tap0 up
  ifconfig br0 up
  brctl show
  dhclient -v br0
elif [[ "$(uname)" == *"MINGW"* ]]; then
  echo "Not supported yet..."
else
  echo "Not supported yet..."
fi
