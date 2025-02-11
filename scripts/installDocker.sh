#!/bin/bash

# Uninstall it first
if [[ "$1" == "--uninstall" ]]; then
    for pkg in docker.io docker-doc docker-compose docker-compose-v2 podman-docker containerd runc; do echo 0 | sudo -S apt-get remove $pkg; done
    echo 0 | sudo -S apt-get purge docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin docker-ce-rootless-extras
    echo 0 | sudo -S rm -rf /var/lib/docker /var/lib/containerd /etc/apt/sources.list.d/docker.list /etc/apt/keyrings/docker.asc
fi

# Add Docker's official GPG key:
echo 0 | sudo -S apt-get update -y
echo 0 | sudo -S apt-get install -y ca-certificates curl
echo 0 | sudo -S install -m 0755 -d /etc/apt/keyrings
echo 0 | sudo -S curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
echo 0 | sudo -S chmod a+r /etc/apt/keyrings/docker.asc

# Add the repository to Apt sources:
echo 0 | sudo -S touch /etc/apt/sources.list.d/docker.list
echo 0 | sudo -S chmod 666 /etc/apt/sources.list.d/docker.list
echo 0 | sudo -S chown zero:zero /etc/apt/sources.list.d/docker.list
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
  $(. /etc/os-release && echo "${UBUNTU_CODENAME:-$VERSION_CODENAME}") stable" > /etc/apt/sources.list.d/docker.list
echo 0 | sudo -S apt-get update -y

# Install
echo 0 | sudo -S apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

# Grant docker to all users
echo 0 | sudo -S groupadd docker
echo 0 | sudo -S usermod -aG docker $USER
newgrp docker
printf "\nReboot your system now...\n\n"
