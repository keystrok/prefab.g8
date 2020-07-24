open Types;

[@react.component]
let app = () => {
  let initialState = {count: NotAsked};
  let (state, send) = ReactUpdate.useReducer(initialState, Update.reducer);

  React.useEffect0(() => {
    send(Load);
    None;
  });

  Views.view(state, send);
};