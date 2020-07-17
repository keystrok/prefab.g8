#!/usr/bin/env bash
set -e

leave_no_trace () {
   rm -- "\${0}"
}

install_reason_react_native () {
  npm install -g react-native-cli
  npx @react-native-community/cli init --template @reason-react-native/template $name;format="Camel"$App
  mv $name;format="Camel"$App app
  mv reasonml_tea/* app/src
  rm -rf reasonml_tea/
}

$if(reason-react-native.truthy)$
  install_reason_react_native

  #TIP: should probably be in a runClient.sh or something
  cd app
  yarn install
  yarn re:build
  #yarn start --reset-cache
  npx react-native run-ios

$endif$

leave_no_trace

echo "# All Done"