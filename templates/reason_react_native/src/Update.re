open Types;

let reducer = (state, action) =>
  switch (action) {
  | Add =>
    switch (state.count) {
    | Ready(x) => {count: Ready(x + 1)}
    | NotReady => state
    }
  | Subtract =>
    switch (state.count) {
    | Ready(x) => {count: Ready(x - 1)}
    | NotReady => state
    }
  };