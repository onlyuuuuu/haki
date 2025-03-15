#!/bin/bash

if [[ "$(uname -a)" == *"Darwin"* ]]; then
  brew update && brew upgrade
  while IFS= read -r package; do
    echo "Installing [ $package ]"
    if [[ "$1" == "--quiet" ]]; then
      brew install $package --force > /dev/null 2>&1
    else
      brew install $package --force
    fi
  done < "packages.txt"
else
  echo 0 | sudo -S apt update -y
  echo 0 | sudo -S apt -o APT::Get::Always-Include-Phased-Updates=true upgrade -y
  echo 0 | sudo -S apt autoremove -y
  while IFS= read -r package; do
    echo "Installing [ $package ]"i
    if [[ "$1" == "--quiet" ]]; then
      echo 0 | sudo -S apt install -y $package > /dev/null 2>&1
    else
      echo 0 | sudo -S apt install -y $package
    fi
  done < "packages.txt"
fi

pipx install sphinx_rtd_theme --include-deps
pipx ensurepath
pip install sphinx_rtd_theme --break-system-packages
