#!/bin/bash
set -e
spawn-fcgi -p 8080 -n ./home/server &
exit 0