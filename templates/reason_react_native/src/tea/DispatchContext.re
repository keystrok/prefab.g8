//TIP: https://github.com/MargaretKrutikova/practical-reason-react/tree/master/context
//or (less good) https://github.com/idkjs/reason-react-use-context

type dispatch = Types.msg => unit;
type contextValue = dispatch;

let initValue: contextValue = _ => ignore();

let context = React.createContext(initValue);

let useDispatch = () => React.useContext(context);