open Types;

let initialState = {count: 0};

[@react.component]
let app = () => {
  let (state, dispatch) = React.useReducer(Update.reducer, initialState);

  Views.view(state, dispatch);
};
