#/bin/bash

if [[ "$(uname)" != "Darwin" ]]; then
  echo 0 | sudo -S ifconfig ens33 down
  echo 0 | sudo -S brctl addbr br0
  echo 0 | sudo -S ip addr flush dev ens33
  echo 0 | sudo -S brctl addif br0 ens33
  echo 0 | sudo -S tunctl -t tap0 -u zero
  echo 0 | sudo -S brctl addif br0 tap0
  echo 0 | sudo -S ifconfig ens33 up
  echo 0 | sudo -S ifconfig tap0 up
  echo 0 | sudo -S ifconfig br0 up
  echo 0 | sudo -S brctl show
  echo 0 | sudo -S dhclient -v br0
elif [[ "$(uname)" == *"MINGW"* ]]; then
  echo "Not supported yet..."
else
  echo "Not supported yet..."
fi
