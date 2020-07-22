type msg =
  | Increment
  | Decrement
  | Failed
  | Success(int);

type count =
  | NotReady
  | Ready(int);

type state = {count};