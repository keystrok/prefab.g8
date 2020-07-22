type msg =
  | Increment
  | Decrement
  | Success(int);

type count =
  | NotReady
  | Ready(int);

type state = {count};

