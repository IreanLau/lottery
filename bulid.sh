#!/bin/bash
PWD=`pwd`
touch result.txt
COMM=common
redisServer="redis/redis-server"
conf=" redis/redis.conf"
make clean

${redisServer} ${conf}
php ${PWD}/${COMM}/getUrlMsg.php > result.txt
make
./fd
