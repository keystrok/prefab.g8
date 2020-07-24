open Types;

let reducer = (action, _state) =>
  switch (action) {
  | Load => ReactUpdate.UpdateWithSideEffects({count: Loading}, Count.load)
  | LoadSuccess(x) => ReactUpdate.Update({count: Loaded(x)})
  | LoadFailed => ReactUpdate.Update({count: LoadError})
  | Increment => ReactUpdate.SideEffects(Count.increment)
  | Decrement => ReactUpdate.SideEffects(Count.decrement)
  };