open Types;
open Shell;
open ReactNative;

let view = (state, dispatch) =>
  <DispatchProvider value=dispatch>
    <Shell>
              <View
                style=Style.(
                  style(
                    ~display=`flex,
                    //            ~flexDirection=`column,
                    ~justifyContent=`center,
                    ~alignItems=`center,
                    ~height=100.->pct,
                    (),
                  )
                )>
                <Button title="-" onPress={_event => dispatch(Subtract)} />
                <Text> {React.string(string_of_int(state.count))} </Text>
                <Button title="+" onPress={_event => dispatch(Add)} />
              </View>
      </Shell>
  </DispatchProvider>;