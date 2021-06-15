let get = (send, url, success, failure) => {
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.text)
    |> then_(x => success(x) |> send |> resolve)
    |> catch(error => failure(error) |> send |> resolve)
    |> ignore
  );
};

let post = (send, url, success, failure) => {
  Js.Promise.(
    Fetch.fetchWithInit(url, Fetch.RequestInit.make(~method_=Post, ()))
    |> then_(Fetch.Response.text)
    |> then_(x => success(x) |> send |> resolve)
    |> catch(error => failure(error) |> send |> resolve)
    |> ignore
  );
};