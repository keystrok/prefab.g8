open Types;

let updateCount = (count, a: int => count): count =>
  switch (count) {
  | Ready(x) => a(x)
  | NotReady => count
  };

let reducer = (state, action) =>
  switch (action) {
  | Increment => {count: updateCount(state.count, x => Ready(x + 1))}
  | Decrement => {count: updateCount(state.count, x => Ready(x - 1))}
  | Success(x) => {count: Ready(x)}
  | Failed => {count: Ready(12019201920192190)}
  };