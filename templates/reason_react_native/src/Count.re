open Types;

let getInitialState = dispatch =>
  Js.Promise.(
    Fetch.fetch("http://localhost:8080/counter")
    |> then_(Fetch.Response.text)
    |> then_(x => int_of_string(x)->Success->dispatch->resolve)
    |> catch(_err => Failed->dispatch->resolve)
  );