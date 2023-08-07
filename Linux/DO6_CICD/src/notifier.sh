#!/bin/sh

TELEGRAM_BOT_TOKEN="6266382075:AAFW7WaPSLCKs_AN43vekLKt9hXfexddB0s"
TELEGRAM_USER_ID="373529287"
started_at=$(date -u -d "$CI_JOB_STARTED_AT + 3 hours" +"%Y-%m-%d %H:%M:%S")
TIME="10 seconds"
emoji="✅"
if [ "$CI_JOB_STATUS" != "success" ] && [ "$CI_JOB_STATUS" != "running" ]; then
    emoji="⛔️"
fi
URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT=""
JOB_INFO=""
if [ -n "$2" ]; then
    TEXT="$1
Project Info:
    Project: $CI_PROJECT_NAME
    Commit by: $CI_COMMIT_AUTHOR
    Commit: $(echo "$CI_COMMIT_MESSAGE" | tr -d '\n')
    URL: "$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID"
    Branch: $CI_COMMIT_REF_SLUG"
    
    JOB_INFO="Info about testing:
    Gitlab user login: $GITLAB_USER_LOGIN
    Gitlab user name: $GITLAB_USER_NAME
    Gitlab user email: $GITLAB_USER_EMAIL
    Job was started at: $started_at
    Job stage: $CI_JOB_STAGE
    Job name: $CI_JOB_NAME"
else
    TEXT="Deploy status: $1 $CI_JOB_STATUS $emoji"
    JOB_INFO="Info about testing:
    Job was started at: $started_at
    Job stage: $CI_JOB_STAGE
    Job name: $CI_JOB_NAME"
fi


curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT%0A$JOB_INFO" $URL > /dev/null
