type msg =
  | Add
  | Subtract
  | Success(int);;

type count =
  | NotReady
  | Ready(int);

type state = {
  count: int,
};