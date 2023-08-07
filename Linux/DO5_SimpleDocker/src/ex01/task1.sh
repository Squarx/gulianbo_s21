#!/bin/bash


docker pull nginx
docker images 
docker run -p 80:80 -p 443:443 -d nginx
docker ps
containerId=$(docker ps | awk '{print $1}' | head -2 | tail -1)
imageId=$(docker images | awk '{print $3}' | head -2 | tail -1)
docker inspect $containerId | grep -i -e "\"ipaddress\"" | head -1
echo  "The total size of all the files in the container, in bytes:
SizeRootFs:"$(docker inspect --size $containerId -f '{{ .SizeRootFs }}')
echo "The size of the files that have been created or changed in the container, compared to it’s image, in bytes.
SizeRw:" $(docker inspect --size $containerId -f '{{ .SizeRw }}') 
sleep 2
curl localhost:80
docker stop $containerId
docker ps
curl localhost:80 
echo "Restarting begin ~3s"
docker restart $containerId
sleep 2
echo "Restarting end"
curl localhost:80