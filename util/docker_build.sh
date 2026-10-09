#!/bin/sh

./util/docker_cmd.sh make "$@" \
    -e USER_NAME=holykeebs \
    -e OLED=stock \
    -j8
