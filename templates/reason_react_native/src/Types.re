type msg =
  | Load
  | RequestSuccess(int)
  | RequestFailure
  | Increment
  | Decrement;

type count =
  | NotAsked
  | Loading
  | Value(int)
  | Broken;

type state = {count};