#!/bin/bash

docker-compose build
docker-compose up -d
docker images
docker ps
curl localhost:80
curl localhost:80/status