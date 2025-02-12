#!/bin/bash

# Run this command first at somewhere that has PERL installed
# perl -p -i.bak -e 's#__SUB__CWD__#'/home/oracle/db-sample-schemas'#g' *.sql */*.sql */*.dat

# Create everything
password=123456789
echo "" | source /usr/local/bin/oraenv
mkdir -p /home/oracle/logs
touch /home/oracle/logs/create-output.log
> /home/oracle/logs/create-output.log
(echo exit | sqlplus system/$password@XEPDB1 @mksample $password $password $password $password $password $password $password $password users temp /home/oracle/logs/ XEPDB1) > /home/oracle/logs/create-output.log 2>&1
