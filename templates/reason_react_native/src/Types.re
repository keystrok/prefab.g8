type msg =
  | Add
  | Subtract;

type count =
  | NotReady
  | Ready(int);

type state = {
  count: int,
};