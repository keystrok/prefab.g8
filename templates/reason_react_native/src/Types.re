type msg =
  | Load
  | LoadSuccess(int)
  | LoadFailed
  | Increment
  | Decrement;

type count =
  | NotAsked
  | Loading
  | Loaded(int)
  | LoadError;

type state = {count};