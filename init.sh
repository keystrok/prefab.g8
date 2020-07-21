#!/usr/bin/env bash
set -e

leave_no_trace () {
   rm -rf templates/
   rm -- "\${0}"
}

install_reason_react_native () {
  npm install -g react-native-cli
  npx @react-native-community/cli init --template @reason-react-native/template $name;format="Camel"$App
  mv $name;format="Camel"$App app
  cp templates/reason_react_native/*.sh app/
  cp -R templates/reason_react_native/src/* app/src/
}

install_dependencies () {
  cd app
  npm install --save bs-fetch
  yarn install
  cd ..
}

$if(reason-react-native.truthy)$
install_reason_react_native
install_dependencies
$endif$

leave_no_trace

echo "# All Done"