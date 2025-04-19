#!/bin/bash

if [[ "$(uname -a)" == *"aarch64"* ]]; then
  echo "This BREW script will now be ignore since aarch64 architecture is detected..."
  exit
fi

if command -v brew > /dev/null 2>&1; then
  echo "Brew already installed, skipping further operations..."
else
  echo "Installing Brew"
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  if [[ "$(uname -a)" == *"Darwin"* ]]; then
    echo "Nothing for MacOS yet..."
  else
    echo >> ~/.zshrc
    echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zshrc
    eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
  fi
fi

if grep 'brew' ~/.zshrc; then
  echo "Brew seems to be sourced, no further actions..."
else
  echo "Sourcing brew by writing into ~/.zshrc now..."
  if [[ "$(uname -a)" == *"Darwin"* ]]; then
    echo "Nothing for MacOS yet..."
  else
    echo >> ~/.zshrc
    echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zshrc
    eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
  fi
fi

brew update
brew upgrade
echo 0 | sudo -S brew cleanup > /dev/null 2>&1
brew clean > /dev/null 2>&1

brew install tlrc

