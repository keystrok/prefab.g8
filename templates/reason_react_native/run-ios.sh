#!/usr/bin/env bash
set -e

yarn install
yarn re:build
yarn start --reset-cache
npx react-native run-ios