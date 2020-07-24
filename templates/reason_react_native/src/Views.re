open Types;
open Shell;
open ReactNative;

let viewCount = (count, send) =>
  switch (count) {
  | NotAsked => <Text> "Initialising..."->React.string </Text>
  | Loading => <Text> "Loading..."->React.string </Text>
  | Broken => <Text> "Error"->React.string </Text>
  | Value(x) =>
    <>
      <Button title="-" onPress={_event => send(Decrement)} />
      <Text> {string_of_int(x)->React.string} </Text>
      <Button title="+" onPress={_event => send(Increment)} />
    </>
  };

let view = (state, send) =>
  <Shell>
    <View style=Styles.styles##content> {viewCount(state.count, send)} </View>
  </Shell>;