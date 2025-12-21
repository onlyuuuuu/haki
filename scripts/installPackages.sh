#!/bin/bash

export NONINTERACTIVE=1

if [[ "$(uname -a)" == *"Darwin"* ]]; then
  brew update && brew upgrade
  while IFS= read -r package; do
    echo "Installing [ $package ]"
    if [[ "$1" == "--quiet" ]]; then
      yes | brew install $package --force > /dev/null 2>&1
    else
      yes | brew install $package --force
    fi
  done < "packages.txt"
else
  echo 0 | sudo -S apt update -y
  echo 0 | sudo -S apt -o APT::Get::Always-Include-Phased-Updates=true upgrade -y
  echo 0 | sudo -S apt autoremove -y
  while IFS= read -r package; do
    echo "Installing [ $package ]"
    if [[ "$1" == "--quiet" ]]; then
      echo 0 | sudo -S apt install -y $package > /dev/null 2>&1
      echo 0 | sudo -S snap install $package --classic --dangerous --devmode > /dev/null 2>&1
      yes | brew install $package --force > /dev/null 2>&1
    else
      echo 0 | sudo -S apt install -y $package
      echo 0 | sudo -S snap install $package --classic --dangerous --devmode
      yes | brew install $package --force
    fi
  done < "packages.txt"
fi

pipx install sphinx_rtd_theme --include-deps
pipx ensurepath
pip install sphinx_rtd_theme --break-system-packages

