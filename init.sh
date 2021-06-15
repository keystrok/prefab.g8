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
  mv templates/reason_react_native/*.sh app/
  cp -R templates/reason_react_native/src/* app/src/

  #detox
  mv templates/reason_react_native/.detoxrc.json app/
  mv templates/reason_react_native/e2e app/e2e/
}

install_dependencies () {
  cd app

  #bs-fetch
  yarn add bs-fetch
  export src='"bs-dependencies": \['
  export replacement=' "bs-dependencies": \["bs-fetch", '
  sed -i '' "s/\$src/\$replacement/" ./bsconfig.json

  #reason-react-update
  yarn add reason-react-update
  export src='"bs-dependencies": \['
  export replacement=' "bs-dependencies": \["reason-react-update", '
  sed -i '' "s/\$src/\$replacement/" ./bsconfig.json

  #detox (js)
  yarn global add detox-cli
  yarn add --dev detox
  #(optional)
  #brew tap wix/brew
  #brew install applesimutils
  yarn add --dev jest jest-cli jest-circus

  #reason-detox
  yarn add --dev jest @glennsl/bs-jest bs-let https://github.com/alltonp/reason-detox
  export src='"bs-dependencies": \['
  export replacement=' "bs-dependencies": \["@glennsl\/bs-jest", "reason-detox", '
  sed -i '' "s/\$src/\$replacement/" ./bsconfig.json
  export replacement2=' "ppx-flags": ["bs-let\/ppx"], "bs-dependencies": \['
  sed -i '' "s/\$src/\$replacement2/" ./bsconfig.json
  export src2='"sources": \['
  export replacement3=' "sources": \[ \{ "dir": "e2e", "type": "dev" \}, '
  sed -i '' "s/\$src2/\$replacement3/" ./bsconfig.json

  cd ios
  pod install
  cd ..
  cd ..
}

$if(reason-react-native.truthy)$
install_reason_react_native
install_dependencies
$endif$

leave_no_trace

echo "# All Done"
