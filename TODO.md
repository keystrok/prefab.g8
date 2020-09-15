- describe how to the the .bs.js hiding using scope `file[direct-app]:*/&&!file[direct-app]:src//*.bs.js`
- add `refreshAndRestart.sh`
    ```
    rm -rf node_modules
    yarn install
    yarn re:build
    yarn start --reset-cache 
    ```