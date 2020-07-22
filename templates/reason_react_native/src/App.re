open Types;

[@react.component]
let app = () => {
  let initialState = {count: NotReady};
  let (state, dispatch) = React.useReducer(Update.reducer, initialState);

  React.useEffect0(() => {
    dispatch(Success(1000));
    None;
  });

  Views.view(state, dispatch);
};
