open Types;

[@react.component]
let app = () => {
 let initialState = {count: Ready(0)};
  let (state, dispatch) = React.useReducer(Update.reducer, initialState);

  Views.view(state, dispatch);
};
