open Types;

let reducer = (state, action) =>
  switch (action) {
  | Add => {count: state.count + 1}
  | Subtract => {count: state.count - 1}
  };