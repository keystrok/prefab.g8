open Types;
open Count;

[@react.component]
let app = () => {
  let initialState = {count: NotReady};
  let (state, dispatch) = React.useReducer(Update.reducer, initialState);

  React.useEffect0(() => {
    getInitialState(dispatch);
    None;
  });

  Views.view(state, dispatch);
};