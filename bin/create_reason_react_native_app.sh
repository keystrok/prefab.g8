#!/usr/bin/env bash
set -e

npm install -g react-native-cli
npx @react-native-community/cli init --template @reason-react-native/template $name;format="Camel"$App
mv $name;format="Camel"$App app
mv ./bin/reasonml_tea/* app/src
cd app
yarn install
yarn re:build
#yarn start --reset-cache
npx react-native run-ios
