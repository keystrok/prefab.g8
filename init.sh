#!/usr/bin/env bash
set -e

leave_no_trace () {
   rm -rf templates/
   rm -- "\${0}"
}

install_reason_react_native () {
  yarn global add react-native-cli
  npx @react-native-community/cli init --template @reason-react-native/template $name;format="Camel"$App
  mv $name;format="Camel"$App app
  cp templates/reason_react_native/*.sh app/
  cp -R templates/reason_react_native/src/* app/src/
}

install_dependencies () {
  cd app
  yarn add bs-fetch
  export src='"bs-dependencies": \['
  export replacement=' "bs-dependencies": \["bs-fetch", '
  sed -i ''  "s/\$src/\$replacement/"  ./bsconfig.json
  cd ..
}

$if(reason-react-native.truthy)$
install_reason_react_native
install_dependencies
$endif$

leave_no_trace

echo "# All Done"