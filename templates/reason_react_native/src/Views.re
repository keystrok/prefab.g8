open Types;
open Shell;
open ReactNative;
let renderCount = count =>
  (
    switch (count) {
    | Ready(x) => string_of_int(x)
    | NotReady => "loading"
    }
  )
  |> React.string;

let view = (state, dispatch) =>
  <DispatchProvider value=dispatch>
    <Shell>
      <View style=Styles.styles##content>
        <Button title="-" onPress={_event => dispatch(Subtract)} />
        <Text> {renderCount(state.count)} </Text>
        <Button title="+" onPress={_event => dispatch(Add)} />
      </View>
    </Shell>
  </DispatchProvider>;