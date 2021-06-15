open Jest;
open ReasonDetox;

describe("The Test", () => {
  testPromise("example", _ => {
    //TIP: everything that returns a Promise must use let%Await
    let%Await _ = expect(Id("count")) |> toHaveText("0");
    let%Await _ = tap(Text("+"));
    let%Await _ = expect(Id("count")) |> toHaveText("1");
    let%Await _ = tap(Text("-"));
    let%Await _ = expect(Id("count")) |> toHaveText("0");

    //TIP: must call this at the end to tell jest we are done, otherwise the test will run until timeout and then fail
    Js.Promise.resolve(pass);
  })
});
