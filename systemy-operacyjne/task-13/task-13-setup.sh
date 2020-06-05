#/bin/bash
DAILY_PATH="$PWD/task-13-daily.sh"
WEEKLY_PATH="$PWD/task-13-weekly.sh"

############################
# Add the jobs to crontab
############################
crontab -l | { cat; echo "24 0 * * 1-6 $DAILY_PATH"; } | crontab -
crontab -l | { cat; echo "24 0 * * 7 $WEEKLY_PATH"; } | crontab -