#!/bin/bash

mkdir -p /home/oracle/logs/
touch /home/oracle/logs/post-startup.log
> /home/oracle/logs/post-startup.log
if [[ -f /opt/oracle/oradata/.installed-schemas ]]; then
    echo "Sample schemas have been installed! Skipping redudant install operations..." >> /home/oracle/logs/post-startup.log
else
    echo "Installing sample schemas..." >> /home/oracle/logs/post-startup.log
    cd /home/oracle/db-sample-schemas
    ./create.sh
    echo "Installed sample schemas!" >> /home/oracle/logs/post-startup.log
    cp -rf /home/oracle/logs/post-startup.log /opt/oracle/oradata/.installed-schemas
fi
