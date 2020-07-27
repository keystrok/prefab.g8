let get = (self, url, success, failure) => {
  ReactUpdate.(
    Js.Promise.(
      Fetch.fetch(url)
      |> then_(Fetch.Response.text)
      |> then_(x => success(x) |> self.send |> resolve)
      |> catch(error => failure(error) |> self.send |> resolve)
      |> ignore
    )
  );
  None;
};

let post = (self, url, success, failure) => {
  ReactUpdate.(
    Js.Promise.(
      Fetch.fetchWithInit(url, Fetch.RequestInit.make(~method_=Post, ()))
      |> then_(Fetch.Response.text)
      |> then_(x => success(x) |> self.send |> resolve)
      |> catch(error => failure(error) |> self.send |> resolve)
      |> ignore
    )
  );
  None;
};