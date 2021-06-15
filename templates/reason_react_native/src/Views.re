open Types;
open Shell;
open ReactNative;

let viewCount = (count, send) =>
  switch (count) {
  | NotAsked => <Text> "Initialising..."->React.string </Text>
  | Loading => <Text> "Loading..."->React.string </Text>
  | Broken(msg) => <Text> {("" ++ msg)->React.string} </Text>
  | Value(v) =>
    <>
      <Button title="-" onPress={_event => send(Decrement)} />
      <Text testID="count"> {string_of_int(v)->React.string} </Text>
      <Button title="+" onPress={_event => send(Increment)} />
    </>
  };

let view = (state, send) =>
  <Shell>
    <View style=Styles.styles##content> {viewCount(state.count, send)} </View>
  </Shell>;