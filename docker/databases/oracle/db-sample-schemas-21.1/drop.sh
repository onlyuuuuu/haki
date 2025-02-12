#!/bin/bash

# Drop everything
password=123456789
echo "" | source /usr/local/bin/oraenv
touch /home/oracle/logs/drop-output.log
> /home/oracle/logs/drop-output.log
(echo exit | sqlplus system/$password@XEPDB1 @drop_sch.sql) >> /home/oracle/logs/drop-output.log 2>&1
# (echo exit | sqlplus system/$password@XEPDB1 @co_drop_user.sql) >> /home/oracle/logs/drop-output.log 2>&1
