#/bin/bash

if [[ "$(uname)" != "Darwin" ]]; then
  echo 0 | sudo -S ifconfig ens33 down
  echo 0 | sudo -S ifconfig tap0 down
  echo 0 | sudo -S ifconfig br0 down
  echo 0 | sudo -S brctl delif br0 tap0
  echo 0 | sudo -S tunctl -d tap0
  echo 0 | sudo -S brctl delif br0 ens33
  echo 0 | sudo -S ifconfig br0 down
  echo 0 | sudo -S brctl delbr br0
  echo 0 | sudo -S ifconfig ens33 up
  echo 0 | sudo -S dhclient -v ens33
elif [[ "$(uname)" == *"MINGW"* ]]; then
  echo "Not supported yet..."
else
  echo "Not supported yet..."
fi
