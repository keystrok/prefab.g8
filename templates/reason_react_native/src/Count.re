open Types;

//TODO: feel like this bit should be in Http
let errorMessage = x => Obj.magic(x);

//TODO: would be nice to kill self... at the very least make it just send
let load = self => {
  ReactUpdate.(
    Http.get(
      self.send,
      "http://localhost:8080/counter",
      text => RequestSuccess(int_of_string(text)),
      error => RequestFailure(errorMessage(error)),
    )
  );
  None;
};

let increment = self => {
  ReactUpdate.(
    Http.post(
      self.send,
      "http://localhost:8080/increment",
      text => RequestSuccess(int_of_string(text)),
      error => RequestFailure(errorMessage(error)),
    )
  );
  None;
};

let decrement = self => {
  ReactUpdate.(
    Http.post(
      self.send,
      "http://localhost:8080/decrement",
      text => RequestSuccess(int_of_string(text)),
      error => RequestFailure(errorMessage(error)),
    )
  );
  None;
};
