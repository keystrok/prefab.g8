open ReactNative;

/* we create a type for the action */
type action =
  | Add
  | Subtract;

/* and do the same for state */
type state = {count: int};

[@react.component]
let app = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Add => {count: state.count + 1}
        | Subtract => {count: state.count - 1}
        },
      {count: 0},
    );

  /* useEffect hook takes 0 arguments hence, useEffect0 */
  React.useEffect0(() => {
    //    let timerId = Js.Global.setInterval(() => dispatch(Tick), 1000);
    //    Some(() => Js.Global.clearInterval(timerId));
    None
  });

  /* ints need to be converted to strings, that are then consumed by React.string */
  <>
    <StatusBar barStyle=`darkContent />
    <SafeAreaView>
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
    </SafeAreaView>
  </>;
};