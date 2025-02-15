#!/bin/bash

docker compose --project-name demo down
if [[ "$1" == "--remove-volumes" ]]; then
    docker volume rm demo_oradata
    docker volume ls
fi
docker ps
