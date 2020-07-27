open Types;

let errorMessage = x => Obj.magic(x);

//TODO: a lot of de-duping to do in here...
let load = self => {
  ReactUpdate.(
    Js.Promise.(
      Fetch.fetch("http://localhost:8080/counter")
      |> then_(Fetch.Response.text)
      |> then_(x =>
           RequestSuccess(int_of_string(x)) |> self.send |> resolve
         )
      |> catch(error =>
           self.send(RequestFailure(errorMessage(error))) |> resolve
         )
      |> ignore
    )
  );
  None;
};
let increment = self => {
  ReactUpdate.(
    Js.Promise.(
      Fetch.fetchWithInit(
        "http://localhost:8080/increment",
        Fetch.RequestInit.make(~method_=Post, ()),
      )
      |> then_(Fetch.Response.text)
      |> then_(x =>
           RequestSuccess(int_of_string(x)) |> self.send |> resolve
         )
      |> catch(_error =>
           self.send(RequestFailure(errorMessage(_error))) |> resolve
         )
      |> ignore
    )
  );
  None;
};
let decrement = self => {
  ReactUpdate.(
    Js.Promise.(
      Fetch.fetchWithInit(
        "http://localhost:8080/decrement",
        Fetch.RequestInit.make(~method_=Post, ()),
      )
      |> then_(Fetch.Response.text)
      |> then_(x =>
           RequestSuccess(int_of_string(x)) |> self.send |> resolve
         )
      |> catch(_error =>
           self.send(RequestFailure(errorMessage(_error))) |> resolve
         )
      |> ignore
    )
  );
  None;
};