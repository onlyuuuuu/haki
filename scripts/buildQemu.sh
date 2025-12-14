#!/bin/bash

first_pull=false
if [[ ! -d /tools/qemu ]]; then
  echo "Compiling and installing QEMU from source"
  cd /tools/
  git clone --depth 1 https://gitlab.com/qemu-project/qemu.git
  first_pull=true
fi

cd /tools/qemu/
# Compare the local and remote HEAD commits
$SCRIPT_DIR/checkForUpdates.sh /tools/qemu
status_code=$?
if [[ "$status_code" == 0 && $first_pull == false ]]; then
  echo "QEMU source is at the latest, no need to do anything..."
else
  echo "Pulling in latest changes from QEMU and installing it now..."
  git pull
  echo 0 | sudo -S rm -rf /tools/qemu/bin/
  mkdir -p /tools/qemu/bin/debug/native
  cd /tools/qemu/bin/debug/native
  ../../../configure --enable-debug --enable-slirp
  #../../../configure
  make -j${nproc}
  echo 0 | sudo -S chown -R $USER:$GROUP /tools/qemu
  echo 0 | sudo -S make install -j${nproc}
  echo 0 | sudo -S chown -R $USER:$GROUP /tools/qemu
fi

