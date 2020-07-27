open Types;

let reducer = (action, _state) =>
  switch (action) {
  | Load => ReactUpdate.UpdateWithSideEffects({count: Loading}, Count.load)
  | RequestSuccess(v) => ReactUpdate.Update({count: Value(v)})
  | RequestFailure(msg) => ReactUpdate.Update({count: Broken(msg)})
  | Increment => ReactUpdate.SideEffects(Count.increment)
  | Decrement => ReactUpdate.SideEffects(Count.decrement)
  };