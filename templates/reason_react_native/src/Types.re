type msg =
  | Load
  | RequestSuccess(int)
  | RequestFailure(string)
  | Increment
  | Decrement;

type count =
  | NotAsked
  | Loading
  | Value(int)
  | Broken(string);

type state = {count};