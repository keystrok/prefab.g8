open Types;

let reducer = (action, _state) =>
  switch (action) {
  | Load => ReactUpdate.UpdateWithSideEffects({count: Loading}, Count.load)
  | RequestSuccess(x) => ReactUpdate.Update({count: Value(x)})
  | RequestFailure => ReactUpdate.Update({count: Broken})
  | Increment => ReactUpdate.SideEffects(Count.increment)
  | Decrement => ReactUpdate.SideEffects(Count.decrement)
  };