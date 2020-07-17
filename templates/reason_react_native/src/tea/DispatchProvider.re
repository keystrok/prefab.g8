let make = React.Context.provider(DispatchContext.context);

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};