#!/bin/bash

if command -v brew > /dev/null 2>&1; then
  echo "Brew already installed, skipping further operations..."
else
  echo "Installing Brew"
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  echo >> ~/.zshrc
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zshrc
  eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
fi

if grep 'brew' ~/.zshrc; then
  echo "Brew seems to be sourced, no further actions..."
else
  echo "Sourcing brew by writing into ~/.zshrc now..."
  echo >> ~/.zshrc
  echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> ~/.zshrc
  eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"
fi

brew update
brew upgrade
brew cleanup

brew install tlrc

