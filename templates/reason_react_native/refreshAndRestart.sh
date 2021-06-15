#!/usr/bin/env bash
set -e

rm -rf node_modules
yarn install
yarn re:build
yarn start --reset-cache
